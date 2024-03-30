#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * ps -ef | grep <> | grep -v grep 을 이용해서 process 를 볼 수 있다.
 * */
int main(int argc, char **argv) {
    /** process pid 를 저장하기 위한 변수 */
    pid_t pid;
    /** 복제 process 생성 */
    pid = fork();
    /** 자식 process */
    if (pid == 0) {
        for (size_t i = 0; i < 3; ++i) {
            printf("\t\t\tchild\r\n");
            /** 1초 대기 */
            sleep(1);
        }
        /** 자식 프로세스 종료 -> 아래 코드가 없으면 계속해서 실행이 된다. */
        exit(0);
    }
    /** 이 코드로 인해서 좀비 process 가 생성 된다. -> defunct */
    while (true) {
        printf("parent\r\n");
        sleep(1);
    }

    return 0;
}

