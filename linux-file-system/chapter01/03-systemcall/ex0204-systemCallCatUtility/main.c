#include <stdio.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#include <memory.h>

#define BUF_MAX         1024

int main(int argc, char **argv) {
    int fd;
    int ret;
    char buffer[BUF_MAX];
    bzero(buffer, sizeof buffer);
    /** 파일 인자가 있을 경우에만 출력할 것이므로 */
    if (argc == 2) {
        fd = open(argv[1], O_RDONLY);
        close(0);
        dup(fd);
    }
    /** 파일을 읽거나 입력을 받아서 처리 하는 logic -> EOF 는 파일의 끝을 의미한다.(control + D)*/
    while ((ret = read(0, buffer, sizeof buffer))) {
        write(1, buffer, ret);
        bzero(buffer, sizeof buffer);
    }
    if (argc == 2) {
        close(fd);
        close(0);
    }
    return 0;
}