#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <memory.h>

#define BUF_MAX     100

int main(int argc, char **argv) {
    /** file descriptor */
    int fd1, fd2;
    /** 읽어온 파일의 내용 숫자 */
    int ret;
    char buffer[BUF_MAX];
    bzero(buffer, sizeof buffer);
    fd1 = open(argv[1], O_RDONLY);
    fd2 = open(argv[1], O_RDONLY);
    /** 2byte 읽기 */
    ret = read(fd1, buffer, 2);
    write(1, buffer, 2);
    bzero(buffer, sizeof buffer);
    ret = read(fd2, buffer, 2);
    write(1, buffer, 2);
    bzero(buffer, sizeof buffer);
    close(fd1);
    close(fd2);
    printf("\r\n");
    return 0;
}