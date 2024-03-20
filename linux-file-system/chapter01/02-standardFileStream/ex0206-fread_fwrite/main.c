#include <stdio.h>
#include <memory.h>
#include <unistd.h>

#define BUFFER_MAX          1024

int main(int argc, char **argv) {
    FILE *fp;
    char buffer[BUFFER_MAX];
    int ret;
    memset(buffer, '\0', BUFFER_MAX);
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("File Open Failed...\r\n");
        return -1;
    }
    /** fread 는 읽은 유효 바이트 수 만큼을 반환한다. */
    while (ret = fread(buffer, 1, sizeof buffer, fp)) {
        usleep(100000);
        fwrite(buffer, 1, ret, stdout);
        fflush(stdout);
    }
    fclose(fp);
    printf("\r\n");
    return 0;
}