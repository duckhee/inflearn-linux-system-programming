#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
/** process 의 종료를 기다리기 위한 header */
#include <sys/wait.h>
/** signal 에 대한 처리를 위한 header */
#include <signal.h>

/** SIGCHLD(자식 프로세스가 종료될 때 발생되는 시그널)을 받아서 처리할 handler 함수 */
void my_signal(int signo);

int main(int argc, char **argv) {
    /** process 의 번호를 저장 하기 위한 변수 */
    pid_t pid;
    /** process 의 종료 코드를 저장 하기 위한 변수 */
    int processStatus;
    /** signal 이 발생 했을 때 처리 하기 위한 event handler 등록 */
    /** 자식 프로세스가 종료가 되었을 때 my_signal 함수를 싫행 시켜준다. */
    signal(SIGCHLD, my_signal);
    /** 자식 프로세스를 생성한다. -> 기계어 코드를 복사 실행 쓰기가 발생 시에 메모리 분리가 일어난다. */
    pid = fork();
    /** 자식 프로세스에서 동작 하기 위한 분기문 */
    if (pid == 0) {
        for (size_t i = 0; i < 3; ++i) {
            printf("\t\t\tchild\r\n");
            sleep(1);
        }
        /** 7이라는 종료 상태 값을 가지고 종료 해주는 함수이다. */
        exit(7);
    }
    /** 자식 프로세스가 종료될 때 반환되는 상태 값을 저장할 인자를 포인터 변수로 받는다. */
//    wait(&processStatus);
    /** 부모 프로세스에서 동작 */
    while (true) {
        printf("parent\r\n");
        sleep(1);
    }
    return 0;
}

/** SIGCHLD(자식 프로세스가 종료될 때 발생되는 시그널)을 받아서 처리할 handler 함수 */
void my_signal(int signo) {
    printf("signal nubmer %d handler call\r\n", signo);
    wait(0);
}
