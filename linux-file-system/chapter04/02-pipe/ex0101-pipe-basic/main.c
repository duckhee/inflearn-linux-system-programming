#include <stdio.h>
#include <memory.h>
#include <unistd.h>

#define BUF_SIZE        1024

int main(void) {
    /** 연결 시켜줄 파이프에 대한 file descriptor 를 저장하기 위한 배열 */
    int fd[2];
    /** 읽어온 갯수를 저장하기 위한 변수 */
    int ret;
    /** 읽어온 값을 저장하기 위한 문자열 변수 */
    char buf[BUF_SIZE];
    memset(buf, '\0', sizeof buf);
    /** pipe 를 생성하는 함수이다. */
    pipe(fd);
    /** 보통 아무것도 하지 않는다면, 0번에는 file descriptor 값이 3이 들어가 있는다.(작은 번호가 읽기 용도로 사용이 되는 file descriptor 가 들어 온다.) */
    printf("fd[0] = %d\r\n", fd[0]);
    /** 보통 아무것도 하지 않는다면, 1번에는 file descriptor 값이 4이 들어가 있는다.(쓰기 용도로 사용이 되는 file descriptor 가 들어 온다.) */
    printf("fd[1] = %d\r\n", fd[1]);
    /** pipe 에 해당 값들에 대해서 쓰기 */
    write(fd[1], "hello", 5);
    /** 파이프에서 값들을 읽어오기 */
    ret = read(fd[0], buf, sizeof buf);
    /** buffer 의 마지막 값을 초기화 진행 */
    buf[ret] = 0;
    printf("buffer read [%s]\r\n", buf);
    /** 읽기 용도의 파이프 종료 */
    close(fd[0]);
    /** 쓰기 용도의 파이프 종료 */
    close(fd[1]);
    return 0;
}
