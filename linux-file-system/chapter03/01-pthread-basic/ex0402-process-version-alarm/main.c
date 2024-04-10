#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

/** 자식 프로세스 종료 신호 시 동작할 함수 */
void my_signal(int signo);


/**
 * process 로 프로그램을 작성하는 것은 알람에 대한 값들이 계속 해서 바뀌어도 동작을 한다.
 * 부모 process와 자식 프로세스가 값이 변경 되는 순간 메모리에 대한 분리가 일어나므로 동작에는 문제가 없으나, 오버 헤드가 발생한다.
 * */
int main(void) {
    int seconds = 0;
    char lines[128];
    char message[65];
    /** 자식 process 가 종료가 되었을 때 시그널 처리 */
    signal(SIGCHLD, my_signal);
    while (1) {
        /** prompt */
        printf("Alarm > ");
        /** terminal 입력을 통해서 받은 값을 해당 배열에 저장 */
        fgets(lines, sizeof lines, stdin);
        /** 동작할 시간과 출력할 메세지에 대해서 해당 형식에 맞게 해당 인자로 저장 */
        sscanf(lines, "%d %64[^\n]", &seconds, message);
        /** process 생성 및 자식 프로세스일 경우 동작 */
        if (fork() == 0) {
            sleep(seconds);
            printf("(%d) %s\r\n", seconds, message);
            /** process 종료 및 종료 코드 전달 */
            exit(0);
        }
    }

    return 0;
}

void my_signal(int signo) {
    printf("my_signal signal code : %d\r\n", signo >>7);
    /** non-blocking 으로 종료된 process 제거 하는 코드이다. */
    while (waitpid(-1, 0, WNOHANG) > 0);
}
