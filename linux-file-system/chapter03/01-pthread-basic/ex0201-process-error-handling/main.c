#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

int main(void) {
    /** file descriptor 를 저장하기 위한 변수 */
    int fd;
    /** 없는 파일을 읽기 모드로 파일 열기 */
    fd = open("AAA", O_RDONLY);
    /** 없는 파일 및 에러가 발생 시 음수 값을 반환한다. */
    if (fd < 0) {
        /** errno는 에러에 대한 정보를 담고 있는 코드이다. -> extern int errno 로 정의된 errno.h 를 추가하면 에러 코드를 담아준다. */
        /** strerror(int errno) 함수는 에러에 대한 상세한 정보를 문자열 형태로 반환을 해준다. */
        printf("[%s]fd = %d\r\n", strerror(errno), errno);
    }

    return 0;
}
