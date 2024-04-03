#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void term_stat(int status) {
    /** 정상 종료에 대한 확인 */
    if (WIFEXITED(status)) {
        /** 정상 종료 코드 값 가져오기 */
        printf("[정상 죵료] exit code : %d\r\n", WEXITSTATUS(status));

    }
        /** 비정상 종료에 대한 signal 종료인지 확인 */
    else if (WIFSIGNALED(status)) {
        /** signal number 와 core dump 유무 확인 */
        printf("[비정상 종료] signal code : %d %s\r\n", WTERMSIG(status), (WCOREDUMP(status)) ? "(core dump)" : "");
    }
}

int main(void) {
    pid_t pid;
    int status;
    pid = fork();
    if (pid == 0) {
        while (true);
    }
    wait(&status);
    term_stat(status);
    return 0;
}
