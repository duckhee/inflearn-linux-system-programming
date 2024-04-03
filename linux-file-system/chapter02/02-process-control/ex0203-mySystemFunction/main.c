#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <memory.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_BUF         1024

int my_system(char *cmd) {
    /** 프로세스 반환 후 상태 값을 가져오기 위한 변수 */
    int status;
    /** 자식 프로세스에 대한 pid 값을 저장하기 위한 변수 */
    pid_t pid;
    /** bin 경로에서 프로세스 파일 찾기 위한 경로 */
    char buffer[MAX_BUF] = "/bin/";
    /** 명령어를 경로에 추가해주기 위한 strcat */
    strcat(buffer, cmd);
    /** 인자로 넘어갈 변수 배열 */
    char *argv[] = {cmd, (char *) 0};
    /** 자식 프로세스 생성 */
    pid = fork();
    /** 자식 프로세스일 경우 kernel 함수인 execve 호출하기 위한 분기문 */
    if (pid == 0) {
        /** /bin/{cmd} 파일을 찾아 실행 시켜주는 kenrel 함수 */
        execve(buffer, argv, 0);
        /** 종료 코드 반환 */
        _exit(127);
    }
        /** 프로세스 생성이 잘못되었을 경우 처리를 위한 분기문 */
    else if (pid < -1) {
        status = -1;
    }
        /** 자식 프로세스가 종료될 때 까지 대기 */
    else {
        waitpid(pid, &status, 0);
    }
    return status;
}

int main(void) {
    int getStatus = 0;
    /** system 함수가 없을 때 우리가 작성한 시스템 콜 호출 */
    getStatus = my_system("ls");
    printf("get call status : %d\r\n", getStatus);
    printf("call done\r\n");
    return 0;
}
