#include <stdio.h>
#include <unistd.h>
#include <memory.h>

#define BUFFER_MAX          1024

int main(int argc, char **argv) {
    FILE *fp;
    char buffer[BUFFER_MAX];
    memset(buffer, '\0', BUFFER_MAX);
    int i;
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("file open failed...\r\n");
        return -1;
    }
    while (fgets(buffer, sizeof buffer, fp)) {
        usleep(100000);
        fputs(buffer, stdout);
        fflush(stdout);
    }
    fclose(fp);
    printf("\r\n");
    return 0;
}