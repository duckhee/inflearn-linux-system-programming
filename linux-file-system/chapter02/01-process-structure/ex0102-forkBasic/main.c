#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
    /** process 의 pid 를 저장하기 위한 변수 */
    pid_t pid = 0;
    /** fork 함수는 pid_t 를 반환하는데 자식 프로세스에는 0을 반환하고, 부모 프로세스에는 자식 프로세스의 pid 를 반환 해준다.*/
    pid = fork();
    /** 부모 process 에서만 실행하기 위한 분기문 */
    if (pid > 0) {
        printf("parent listen\r\n");
    }
    /** 자식 process 에서만 실행하기 위한 분기문 */
    else if (pid == 0) {
        printf("child process listen\r\n");
    }
        /** fork 함수의 에러 처리를 위한 분기문 */
    else{
        /** 에러가 발생한 것을 열려주는 함수 */
        perror("fork error\r\n");
    }
    printf("Hello : %d\r\n", pid);
    return 0;
}
