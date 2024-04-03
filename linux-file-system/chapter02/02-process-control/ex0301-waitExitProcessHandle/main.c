#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv) {
    /** process 의 pid 를 저장하기 위한 변수 */
    pid_t pid;
    /** process status 저장을 위한 변수 */
    int status = 0;
    /** child process 생성 */
    pid = fork();
    /** child process logic */
    if (pid == 0) {
        exit(7);
    }
    /** 자식 프로세스가 종료될 때 값을 저장하기 위한 변수를 인자로 받으면서 자식 프로세스가 종료될 때 까지 대기하는 함수이다. */
    wait(&status);
    /** 정상 종료인지 확인하기 위한 분기문 */
    if ((status & 0x7F) == 0) {
        /** 상태 값을 status 에 담겨 있는 것을 오른쪽으로 8bit 만큼 이동 시키면, 종료될 때 받은 상태 값을 구할 수 있다. */
        printf("[exit-success] get status : %d\r\n", (status >> 8) & 0xFF);
    }

    return 0;
}
