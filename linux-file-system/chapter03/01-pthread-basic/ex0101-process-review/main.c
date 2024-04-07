#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>


int main(void) {
    /** 프로셋스 번호를 저장하기 위한 변수 */
    pid_t pid;
    /** 프로세스 생성 */
    pid = fork();
    /** 자식 프로세스일 경우 동작 */
    if (pid == 0) {
        printf("child process\r\n");
        /** 종료 값을 전달하면서 종료 하는 함수 */
        exit(0);
    }
    /** 자식 프로세스가 종료가 될 때까지 기다리기 위한 함수 */
    wait(0);
    printf("parent process\r\n");
    return 0;
}
