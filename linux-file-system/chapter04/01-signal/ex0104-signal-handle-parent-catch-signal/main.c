#include <stdio.h>
#include <signal.h>
#include <unistd.h>

#define NUM_CHILD       3

int main(int argc, char **argv) {
    /** 부모 process 의 값을 저장하기 위한 변수 */
    int pid;
    /** 자식 process 의 값을 저장하기 위한 배열 */
    int chpid[NUM_CHILD];

    for (size_t i = 0; i < NUM_CHILD; i++) {
        /** 부모 process 일 경우 동작 */
        if ((pid = fork()) == 0) {
            /** kernel 에서 특정 프로그램을 실행 */
            execlp("../ex0104-signal-handle-child-catch-signal/buildDir/ex0104SignalHandleChildProcess", "./ex0104SignalHandleChildProcess", (void *) NULL);
        }
        /** process 를 저장하는 것 */
        chpid[i] = pid;
    }
    printf("sig_parent : %d child process run \r\n", NUM_CHILD);
    /** 대기 하는 함수 */
    sleep(10);

    for (size_t i = 0; i < NUM_CHILD; i++) {
        /** process 를 종료하면서 신호 보내기 */
        kill(chpid[i], SIGINT);
    }
    return 0;
}
