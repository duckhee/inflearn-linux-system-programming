#include <stdio.h>
#include <unistd.h>
#include <signal.h>

/** signal 처리하는 함수 */
void handler(int sig) {
    /** getpid 는 자기 자신의 pid 값을 출력하는 함수이다. */
    printf("child die (%d)\r\n", getpid());
}

int main(void) {
    /** signal 발생 시 처리할 함수 등록 */
    signal(SIGINT, handler);
    /** signal 처리를 대기하기 위한 함수 */
    pause();
    return 0;
}
