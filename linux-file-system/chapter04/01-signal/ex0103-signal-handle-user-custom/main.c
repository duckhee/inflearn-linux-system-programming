#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

/** 신호에 대한 처리를 위한 함수 */
void handler(int sig) {
    printf("signal no(%d) Received\r\n", sig);
}

int main(void) {
    /** 사용자 정의가 되어 있는 신호일 경우 동작 -> 신호 값이 10번 */
    if (signal(SIGUSR1, handler) == SIG_ERR) {
        fprintf(stderr, "can not set USER1 \r\n");
        return 1;
    }
    /** 사용자 정의가 되어 있는 신호일 경우 동작 -> 신호 값이 12번 */
    if (signal(SIGUSR2, handler) == SIG_ERR) {
        fprintf(stderr, "can not set USER2 \r\n");
        return 1;
    }
    for (;;)
        /** 시그널에 대한 대기하기 위한 함수 */
        pause();
    return 0;
}
