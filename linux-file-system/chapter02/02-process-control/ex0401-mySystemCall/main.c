#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/** system 함수를 구현한 함수이다 */
int my_system(const char *cmd);

int main(void) {
    my_system("ls -al");
    printf("after\r\n");
    return 0;
}

int my_system(const char *cmd) {
    /** 프로세스의 pid 를 저장하기 위한 분석 */
    pid_t pid;
    /** 프로세스의 종료 값을 저장하기 위한 변수 */
    int status;
    /** 프로세스 생성 */
    pid = fork();
    /** 자식 프로세스일 경우 동작하는 분기문 */
    if (pid == 0) {
        /** 환경 변수를 가지고 해당 위치 부터 해당 명령어를 찾아서 실행하는 함수 이다. -> 전부 구현하기 위해서는 parsing 에 대한 처리 로직이 있어야한다. */
//        execlp(cmd, cmd, (char *) 0);
        /** option 에 대한 처리를 하기 위해서 shell 로 실행 시킨다. */
        execl("/bin/sh", "sh", "-c", cmd, (char *) 0);
        /** 정상적으로 실행이 되지 않았을 때 반환하는 값이 127이다. */
        _exit(127);
    }
        /** 부모 프로세스가 동작하는 분기문 */
    else if (pid > 0) {
        /** 프로세스가 종료할 때 까지 대기하기 위한 함수 */
        waitpid(pid, &status, 0);
    }
        /** 에러가 발생했을 때 처리 분기문 */
    else {
        status = -1;
    }
    return status;
}
