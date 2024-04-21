#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void my_handler(int signo) {
    printf("my sig(%d)\r\n", signo);
    /** 주기적으로 동작하기 위한 알람 등록 */
    alarm(3);
}

int main(void) {
    /** signal 에 대한 처리하는 함수 등록 -> alarm 발생 시 동작한다. */
    signal(SIGALRM, my_handler);
    /** 알람을 등록하는 함수 3초 후 등록 */
    alarm(3);
    /** 신호가 올 때까지 대기하는 함수 */
//    pause();
    /** 알람 신호는 기본 동작이 프로세스 종료이므로 해당 무한 루프가 종료가 된다. */
    while (1);
    return 0;
}
