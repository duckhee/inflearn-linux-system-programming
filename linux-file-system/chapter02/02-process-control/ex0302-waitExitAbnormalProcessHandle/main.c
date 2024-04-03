#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
    /** child process pid variable */
    pid_t pid;
    /** child status variable */
    int status;
    /** child process create */
    pid = fork();
    /** only child process run do */
    if (pid == 0) {
        /** not stop child process */
        while (true);
    }
    /** waiting child process dead */
    wait(&status);
    /** normal exit child process */
    if ((status & 0x7F) == 0) {
        /** get process normal exit status code */
        printf("[success-exit] process exit status code : %d\r\n", (status >> 8) & 0xFF);
    }
        /** abnormal exit child process */
    else {
        /** get signal code */
        printf("[abnormal-exit] process signal code : %d\r\n", (status & 0xFF));
    }

    return 0;
}
