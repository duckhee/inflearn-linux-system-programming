#include <stdio.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#include <memory.h>

#define BUF_MAX         1024

int main(int argc, char **argv) {
    int fd;
    int ret;
    char buffer[BUF_MAX];
    bzero(buffer, sizeof buffer);
    /** 파일을 쓰기 모드이면서 파일이 존재하면 덮어쓰기 위한 파일 모드로 연다. */
    fd = open(argv[1], O_WRONLY | O_TRUNC | O_CREAT, 0666);
    /** 모니터의 연결을 종료한다. */
    close(1);
    /** 파일 디스크립터 배열의 빈 곳에 해당 파일 디스크립터를 복제한다. */
    dup(fd);
    /** 해당 출력이 파일에 쓰이게 된다. -> printf 는 write(1)을 수행하는 것과 같다. */
    printf("Hello world\r\n");
    close(fd);
    return 0;
}