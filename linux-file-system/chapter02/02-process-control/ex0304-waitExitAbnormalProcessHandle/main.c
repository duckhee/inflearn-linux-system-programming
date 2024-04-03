#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void term_stat(int status) {
    if (WIFEXITED(status)) {
        printf("[정상 죵료] exit code : %d\r\n", WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
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
