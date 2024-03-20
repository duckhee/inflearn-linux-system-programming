#include <stdio.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <memory.h>

#define BUF_MAX     100

int main(int argc, char **argv) {
    /** file descriptor */
    int fd;
    /** 읽어온 파일의 내용 숫자 */
    int ret;
    char buffer[BUF_MAX];
    bzero(buffer, sizeof buffer);
    fd = open(argv[1], O_RDONLY);
    /** 2byte 읽기 */
    ret = read(fd, buffer, 2);
    write(1, buffer, 2);
    ret = read(fd, buffer, 2);
    write(1, buffer, 2);
    close(fd);
    printf("\r\n");
    return 0;
}