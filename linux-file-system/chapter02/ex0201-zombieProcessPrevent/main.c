#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
/** wait 함수를 사용하기 위한 header */
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv) {
    /** process pid 를 저장하기 위한 변수 */
    pid_t pid;
    /** 종료된 process 의 상태를 가져오기 위한 변수 */
    int pidStatus = 0;
    /** process 를 만들기 위한 fork 함수 */
    pid = fork();
    /** 자식 프로세스에서 실행이 되기 위한 분기문 */
    if (pid == 0) {
        for (size_t i = 0; i < 3; ++i) {
            printf("\t\t\tChild\r\n");
            sleep(1);
        }
        /** process 종료 시의 상태 코드 값 */
        exit(7);
    }
    /** wait 함수는 종료가된 프로세스의 pid 를 반환하며 인자로는 종료된 process 의 상태 값을 저장하기 위한 변수를 인자로 받는다. */
    pid = wait(&pidStatus);
    /** 상태 종료 값은 상위 2번쨰 바이트에 저장이 되므로 해당 값을 찾기 위해서 오른쪽으로 bit shift 를 한다. -> pidStatus >> 8 */
    printf("child process : %d process-status : %d\r\n", pid, pidStatus >> 8);
    /** 정상 종료인지 확인하는 분기문 */
    if (0 == (pidStatus & 0xFF)) {
        printf("success process get status : %d\r\n", (pidStatus >> 8));
    }
        /** 시그널 번호를 찾기 위한 분기문 */
    else {
        printf("signal status : %d\r\n", pidStatus);
    }
    while (true) {
        printf("parent\r\n");
        sleep(1);
    }
    return 0;
}
