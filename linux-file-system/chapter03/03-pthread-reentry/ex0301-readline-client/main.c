#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE         1024

int main(void) {
    int fd;
    char buffer[MAX_BUFFER_SIZE];
    /** fifo 는 kernel 내부에 있는 64K 메모리 이고, 간단한 프로세스 별 IPC 형태로 쓰일 수 있는 구조이다. */
    /** shell 에서 mkfifo 를 이용해서 fifo 를 생성할 수 있다. */
    fd = open("myfifo", O_RDWR);
    if (fd <= 0) {
        printf("file descriptor open failed\r\n");
        return -1;
    }
//    write(fd, "hello\n", 6);
//    getchar();
    /** fd 에 쓰기 */
    write(fd, "he", 2);
    getchar();
    write(fd, "ll", 2);
    getchar();
    write(fd, "o\n", 2);
    getchar();
    return 0;
}
