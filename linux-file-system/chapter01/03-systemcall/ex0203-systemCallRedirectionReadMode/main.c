#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <memory.h>

#define BUF_MAX         1024

/**
 * 파일을 읽어서 해당 값을 화면에 출력 하는 프로그램
 * @param argc
 * @param argv
 * @return
 */

int main(int argc, char **argv) {
    int fd;
    int ret;
    char buffer[BUF_MAX];
    bzero(buffer, sizeof buffer);
    /** 읽기 모드로 파일 열기 */
    fd = open(argv[1], O_RDONLY);
    /** 키보드 입력에 대한 file descriptor 종료 */
    close(0);
    /** file descriptor 를 담고 있는 배열에 빈곳에 현재 file descriptor 를 복사 */
    dup(fd);
    read(0, buffer, sizeof buffer);
    write(1, buffer, ret);
    close(fd);
    return 0;
}