#include <stdio.h>
#include <memory.h>

#define BUFFER_MAX          1024

int main(int argc, char **argv) {
    char buffer[BUFFER_MAX];
    memset(buffer, '\0', BUFFER_MAX);
    int ret;
    FILE *fp;
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("file read failed...\r\n");
        return -1;
    }
    ret = fread(buffer, 1, 2, fp);
    fwrite(buffer, 1, ret, stdout);
    getchar();

    ret = fread(buffer, 1, 2, fp);
    fwrite(buffer, 1, ret, stdout);
    printf("\r\n");
    fclose(fp);
    return 0;
}