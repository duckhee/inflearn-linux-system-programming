#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>


int main(void) {
    /** 프로세스의 pid 값을 저장할 변수 */
    pid_t pid;
    /** 프로세스 종료에 대한 상태 값을 담을 변수 */
    int status;
    /** 자식 프로세스 생성하는 함수 */
    pid = fork();
    if (pid == 0) {
        while (true);
    }
    /** 자식 프로세스에 대한 종료를 기다리는 함수*/
    wait(&status);
    /** 종료 코드를 받아서 정상 종료된 경우 */
    if ((status & 0x7F) == 0) {
        printf("[정상 종료] exit status number : %d\r\n", (status >> 8) & 0xFF);
    }
        /** 정상 종료가 아닌 signal 을 받아서 종료 되었을 때 처리 */
    else {
        printf("signal hex : %x\r\n", (status & 0xFF));
        /** 리눅스에서 core dump 파일이 생성이 되는 signal 일 경우 동작하는 코드 -> 0x80 은 1byte의 8번째 비트의 값을 나타낸다. */
        if (status & 0x80) {
            printf("core dump\r\n");
        }

        printf("[비정상 종료] abnormal exit signal number : %d %s\r\n", (status & 0xFF),
               (status & 0x80) ? "(core dump)" : "");
    }
    return 0;
}
