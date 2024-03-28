#include <stdio.h>
/** mknod 를 사용하기 위한 header */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv) {
    /** block device 를 생성해주는 함수 이다. -> mac 에서는 root 권한으로 실행해야한다. */
    /** 파일의 이름, 접근 모드, 메이져번호와 마이너 번호를 넣어준다. (현재 메이저 번호는 3, 마이너 번호는 1 이다.) */
    mknod("mydev", 0666 | S_IFCHR, 1 << 8 | 1);
    getchar();
    /** inode 의 연결을 끊는 함수 이다. */
    unlink("mydev");
    return 0;
}
