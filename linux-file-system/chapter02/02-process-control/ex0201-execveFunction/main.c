#include <unistd.h>
#include <stdio.h>

int main(void) {
    char *argv[] = {"ls", "-al", (char *) 0};
    /** kernel 이 사용하는 함수이다. -> 인자로 파일의 이름(절대 경로), 인자로 넘길 값, 환경 변수 배열을 인자로 받는다. */
    execve("/bin/ls", argv, NULL);
    /** 출력이 되지 않는다. */
    printf("after\r\n");
    return 0;
}
