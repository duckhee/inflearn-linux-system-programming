#include <stdio.h>
/** 시스템에서 제공하는 파일 열기 및 읽기 쓰기를 위한 header */
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <memory.h>

#define BUF_MAX         1024

int main(int argc, char **argv) {
    /** file description number 를 담을 int 값 */
    int fd;
    int ret;
    char buffer[BUF_MAX];
    memset(buffer, '\0', BUF_MAX);
    /** 시스템 콜을 이용한 파일 열기 */
    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        printf("File Open Failed...\r\n");
        return -1;
    }
    while ((ret = read(fd, buffer, sizeof buffer))) {
        write(1, buffer, ret);
        bzero(buffer, sizeof buffer);
    }
    close(fd);
    printf("\r\n");
    return 0;
}