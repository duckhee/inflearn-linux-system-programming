#include <stdio.h>
#include <memory.h>

#define BUFFER_MAX          1024

int main(int argc, char **argv) {
    FILE *fp;
    int ret;
    char buffer[BUFFER_MAX];
    memset(buffer, '\0', BUFFER_MAX);
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("File open failed ...\r\n");
        return -1;
    }
    while ((ret = fread(buffer, sizeof(char), sizeof buffer, fp))) {
        fwrite(buffer, 1, ret, stdout);
        memset(buffer, '\0', BUFFER_MAX);
    }
    fclose(fp);
    printf("\r\n");
    return 0;
}