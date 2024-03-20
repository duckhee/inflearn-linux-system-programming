#include <stdio.h>
#include <memory.h>
#include <fcntl.h>

#define BUF_MAX             1024
#define FILE_NAME_MAX       20

typedef struct _FileInfo {
    char fname[FILE_NAME_MAX];
    int fsize;
} FileInfo;

int main(int argc, char **argv) {
    FILE *src;
    FILE *dst;
    FileInfo info;
    /** 파일에서 읽어온 갯수를 저장하기 위한 변수 */
    int ret;
    /** 파일의 사이즈를 저장하기 위한 변수 */
    int len;
    char buffer[BUF_MAX];
    memset(buffer, '\0', BUF_MAX);

    if (argc != 2) {
        printf("usage: extract source\r\n");
        return -1;
    }

    src = fopen(argv[1], "r");
    while (fread(&info, sizeof(FileInfo), 1, src)) {
        dst = fopen(info.fname, "w");
        while (info.fsize > 0) {
            /** buffer 와 파일의 크기를 비교해서 작은 값을 넣어준다. */
            len = (sizeof(buffer) < info.fsize) ? sizeof(buffer) : info.fsize;
            ret = fread(buffer, sizeof(char), len, src);
            fwrite(buffer, sizeof(char), ret, dst);
            memset(buffer, '\0', BUF_MAX);
            /** 반복에 대한 횟수를 세기 위한 남은 파일 사이즈 구하는 방법 */
            info.fsize -= ret;
        }


        fclose(dst);
    }
    fclose(src);
    return 0;
}