#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <memory.h>
#include <fcntl.h>
/** socketpair 를 호출하기 위한 header */
#include <sys/socket.h>

/** waitpid 를 이용해서 자식 프로세스를 수거하는 함수 */
void sigchld_handler(int sigNo);

/** 데이터를 쓰기 위한 변수 */
int g_signal_fd;
/** 데이터를 가져올 때 사용하기 위한 변수 */
int g_signal_receive_fd;

/** signal file descriptor 에 특정 값을 써줘서 자식 프로세스를 수거하는 함수 */
void signal_fd_handler(int sigNum);

int main(int argc, char **argv) {
    /** process pid 를 저장하기 위한 변수 */
    pid_t pid;
    /** socket 에서 생성된 file descriptor 를 저장하기 위한 변수 */
    int socket_pd[2] = {0,};
    /** socket 에서 전송 받은 1byte 데이터를 저장하기 위한 함수 */
    char getData;
    /** signal 을 받아서 동작하기 위한 handler 함수를 조금 더 상세히 설정 하기 위한 구조체 */
    struct sigaction act = {0,};
    /** 구조체 초기화 */
    memset(&act, '\0', sizeof(act));
    /** signal 이 밸생이 되었을 때 실행할 함수에 대해서 등록 */
    act.sa_handler = signal_fd_handler;
    /** 자식 프로세스가 종료가 되었을 때만 실행이 되도록 해주는 옵션 설정 */
    act.sa_flags = SA_NOCLDSTOP;
    /** 특정 시그널이 들어오면 동작하도록 하는 함수 -> signal 함수와 동일한 역활을 하지만 조금 더 상세히 제어가 가능하다. */
    sigaction(SIGCHLD, &act, 0);
    /** 짝이 되는 socket 을 생성하는 함수이다. */
    socketpair(AF_UNIX, SOCK_STREAM, 0, socket_pd);
    /** 쓰기 전용을 쓰기 위한 소켓 설정 */
    g_signal_fd = socket_pd[0];
    /** 읽기 전용을 쓰기 위한 소켓 설정 */
    g_signal_receive_fd = socket_pd[1];
    /** process 복제를 하기 위한 프로세스 생성 */
    pid = fork();
    if (pid == 0) {
        for (size_t i = 0; i < 3; ++i) {
            printf("\t\t\tchild\r\n");
            sleep(1);
        }
        exit(7);
    }
    while (true) {
        printf("parent\r\n");
        /** read 전용의 socket 에서 1 byte 의 값을 읽어오기 */
        read(g_signal_receive_fd, &getData, 1);
//        while (waitpid(-1, 0, WNOHANG) > 0);
        if (getData == 'W') {
            printf("remove child process\r\n");
            write(g_signal_fd, 0, 1);
            while (waitpid(-1, 0, WNOHANG) > 0);
        }
        printf("child process remove\r\n");
        sleep(1);
    }
    return 0;
}

/** waitpid 를 이용해서 자식 프로세스를 수거하는 함수 */
void sigchld_handler(int sigNo) {
    printf("signal handler get sig -> %d\r\n", sigNo);
    while (waitpid(-1, 0, WNOHANG) > 0);
}

/** signal file descriptor 에 특정 값을 써줘서 자식 프로세스를 수거하는 함수 */
void signal_fd_handler(int sigNum) {
    char sendData = 'W';
    printf("signal number : %d, socket write command \r\n", sigNum);
    /** 쓰기 기능을 쓰기 위해서 등록 시켜둔 socketpair 의 소켓에 1byte 만큼 작성을 해준다. */
    write(g_signal_fd, &sendData, 1);
}
