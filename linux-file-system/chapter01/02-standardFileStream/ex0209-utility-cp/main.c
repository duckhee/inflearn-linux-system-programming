#include <stdio.h>
#include <memory.h>

#define BUFFER_MAX          1024

int main(int argc, char **argv) {
    FILE *src, *dst;
    int ret;
    char buffer[BUFFER_MAX];
    memset(buffer, '\0', BUFFER_MAX);
    if (argc != 3) {
        printf("usage : cp source file dest file\r\n");
        return -1;
    }
    src = fopen(argv[1], "r");
    if (src == NULL) {
        printf("Source File Open Failed...\r\n");
        return -1;
    }
    dst = fopen(argv[2], "w");
    if (dst == NULL) {
        printf("Dest File Open Failed...\r\n");
        return -1;
    }
    while ((ret = fread(buffer, sizeof(char), sizeof buffer, src))) {
        fwrite(buffer, sizeof(char), ret, dst);
    }
    fclose(dst);
    fclose(src);
    return 0;
}