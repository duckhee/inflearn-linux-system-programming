#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <memory.h>

#define BUF_MAX     100

int main(int argc, char **argv) {
    /** file description 하고, 읽어온 개수에 대해서 저장할 변수 */
    int fd, ret;
    /** 읽어온 데이터를 임시 저장하기 위한 변수 */
    char buffer[BUF_MAX];
    /** 데이터 버퍼 초기화 */
    bzero(buffer, sizeof buffer);
    /** 파일 열기 -> O_RDWR(파일을 읽기 쓰기 모드로 열기), O_CREAT(파일이 없으면 생성), O_TRUNC(파일을 생성할 때, 이미 있는 파일일 경우 내용을 모두 지우고, 파일의 길이를 0으로 변경) */
    fd = open("zzz", O_RDWR | O_CREAT | O_TRUNC, 0666);
    /** 일시 멈춤을 위한 getchar */
    getchar();
    /** 파일에 대한 inode 삭제 -> 이 시점에 파일에 대한 이름이 삭제가 된다. */
    unlink("zzz");
    /** 일시 멈춤을 위한 getchar */
    getchar();
    /** 파일에 데이터 쓰기 -> unlink 이후에도 파일에 쓸 수 있다. */
    write(fd, "hello\r\n", 6);
    /** 파일의 맨 앞 위치로 커서를 이동시킨다. */
    lseek(fd, 0, SEEK_SET);
    /** 파일에서 데이터 읽어오기 -> unlink 이후에도 파일을 읽어올 수 있다. */
    ret = read(fd, buffer, sizeof buffer);
    /** 읽어온 데이터를 화면에 출력 */
    write(1, buffer, ret);

//    for (;;);
    getchar();

    return 0;
}
