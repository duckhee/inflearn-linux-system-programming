#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

/** global 변수 선언 -> 자식 프로세스에서 변경을 하면 그때 메모리 복사를 진행해서 부모 프로세스와 값이 달라진다. */
int g_value = 6;

int main(void) {
    /** process 의 ID 값을 저장하기 위한 변수 */
    pid_t pid;
    /** process 생성해서 pid 값을 저장한다. */
    pid = fork();
    /** 자식 프로세스가 동작하기 위한 분기문 */
    if (pid == 0) {
        /** 여기서 global 변수에 접근해서 값을 변경 하는 순간 새로운 메모리를 복사를 해서 분리가 된다. -> copy on write */
        printf("child process global value :%d \r\n", ++g_value);
        /** 자식 프로세스를 종료하기 위한 변수 */
        exit(0);
    }
    /** 자식 프로세스가 종료가 될때까지 기다리는 함수 */
    wait(0);
    /** global 변수에 대한 값을 확인하기 위한 출력 */
    printf("parent process global value : %d \r\n", g_value);
    return 0;
}
