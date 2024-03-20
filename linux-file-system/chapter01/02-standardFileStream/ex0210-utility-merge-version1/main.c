#include <stdio.h>
#include <string.h>
#include <memory.h>

#define BUF_MAX         1024

#define FILE_NAME_MAX       20

typedef struct _FileInfo {
    char fname[FILE_NAME_MAX];
    int fsize;
} FileInfo;

int getFileSize(FILE *fp);

int main(int argc, char **argv) {
    FILE *dst;
    FILE *src;
    int ret;
    FileInfo info;
    char buffer[BUF_MAX];
    memset(buffer, '\0', BUF_MAX);
    if (argc < 4) {
        printf("usage: merge source1 source2 ... dest\r\n");
        return -1;
    }
    dst = fopen(argv[argc - 1], "w");

    for (int i = 0; i < argc - 2; i++) {
        memset(info.fname, '\0', sizeof(info.fname));
        strcpy(info.fname, argv[i + 1]);
        src = fopen(argv[i + 1], "r");
        info.fsize = getFileSize(src);
        fwrite(&info, sizeof(FileInfo), 1, dst);
        while ((ret = fread(buffer, sizeof(char), sizeof buffer, src))) {
            fwrite(buffer, sizeof(char), ret, dst);
            memset(buffer, '\0', BUF_MAX);
        }
        fclose(src);
    }

    fclose(dst);
    return 0;
}

int getFileSize(FILE *fp) {
    int fsize, fpos;
    fpos = ftell(fp);
    fseek(fp, 0, SEEK_END);
    /** file 의 현재 위치를 반환하는 함수가 ftell 이다. */
    fsize = ftell(fp);
    fseek(fp, fpos, SEEK_SET);
    return fsize;
}