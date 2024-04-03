#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    char *argv[] = {"ls", (char *) 0};
    printf("prompt> ls \r\n");
    /** 자식 프로세스를 만들어서 해당 시스템 코드를 호출하도록 하기 위한 분기문 */
    if (fork() == 0) {
        /** 외부 프로세스 실행을 시키는 함수 -> kernel 에서 사용하는 시스템 콜이다. */
        execve("/bin/ls", argv, NULL);
    }
    /** 자식 프로세스가 종료될 때 까지 기다리는 함수 */
    wait(0);
    /** dead code 가 되지 않는지 확인하기 위한 출력 */
    printf("prompt>\r\n");
    return 0;
}


