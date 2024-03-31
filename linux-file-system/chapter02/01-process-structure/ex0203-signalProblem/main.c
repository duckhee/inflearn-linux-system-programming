#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>

/** signal 함수는 process 가 바쁜 상황에서는 제대로 자식 프로세스가 수거가 되지 않는 문제가 있다. */
void signal_handler(int sigNo);

int main(int argc, char **argv) {
    /** 프로세스 번호를 저장 하기 위한 변수 */
    pid_t pid;
    /** 자식 프로세스 종료 시 실행할 함수 등록 -> 이벤트 핸들러 */
    /** 함수가 실행 중에 요청이 온 프로세스일 경우 무시가 된므로 좀비 프로세스가 생성될 가능성이 있다. */
    signal(SIGCHLD, signal_handler);
    for (size_t i = 0; i < 3; ++i) {
        /** 프로세스 생성 -> 자식 프롯세스를 생성해주는 함수 이다. */
        pid = fork();
        /** 자식 프로세스에서 실행 하기 위한 분기문 */
        if (pid == 0) {
            for (size_t j = 0; j < i + 1; ++j) {
                printf("\t\t\tchild : %d\r\n", i);
                sleep(1);
            }
            /** 종료 코드 값을 7로 남기고 프로세스 종료 */
            exit(7);
        }
    }
    while (true) {
        printf("parent\r\n");
        sleep(1);
    }
    return 0;
}

void signal_handler(int sigNo) {
    printf("signal call handler - %d\r\n", sigNo);
    /** wait 가 덜 호출이 되어도 정상적으로 수거가 될 때 정상적으로 수거가 된다면, 0보다 큰 값이 자식의 프로세스의 PID를 반환하므로 계속해서 수거를 진행을 한다. -> 수거할 프로세스가 없을 경우에는 음수를 반환한다. */
    /** 시간차로 자식 프로세스가 종료가 된다면, parent 코드가 실행이 되지 않고, 전체 프로세스가 종료될 때까지 부모 코드는 실행이 안된다. */
//    while (wait(0) > 0);
    /** 부모 process 를 blocking 하지 않고 동작 하도록 해주는 함수이다. */
    while (waitpid(-1, 0, WNOHANG) > 0);
}
