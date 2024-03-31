#include <stdio.h>
#include <unistd.h>


int main(int argc, char **argv) {
    /** 현재 실행 중인 process 를 복제 하는 함수이다. */
    fork();
    printf("after\r\n");
    return 0;
}
