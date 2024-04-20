#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

/** signal handler 함수는 void 반환이면서 int 형 인자를 받는다. */
void catchSignal(int signum) {
    printf("SIGINT receive\r\n");
}

int main(void) {
    /** SIGINT (Signal Interrupt) 발생 했을 때 실행을 할 함수를 등록이 가능하다.  */
    signal(SIGINT, catchSignal);
    printf("sleep call #1\r\n");
    sleep(1);
    printf("sleep call #2\r\n");
    sleep(1);
    printf("sleep call #3\r\n");
    sleep(1);
    printf("sleep call #4\r\n");
    sleep(1);
    printf("exit\r\n");
    exit(0);
}
