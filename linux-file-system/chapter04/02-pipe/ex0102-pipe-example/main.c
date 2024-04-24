#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <unistd.h>

#define MSGSIZE         16
#define MAX_SIZE        1024

/** 전달할 메세지 포맷 */
char *msg1 = "hello, world #1";
char *msg2 = "hello, world #2";
char *msg3 = "hello, world #3";

int main(void) {
    /** 임시 저장할 pipe buffer 생성 */
    char inBuf[MAX_SIZE];
    /** 읽어온 갯수만큼 저장하는 변수 */
    int ret;
    /** buffer 초기화 */
    memset(inBuf, '\0', MAX_SIZE);
    /** pipe descriptor 에 대한 저장 하기 위한 문자열 변수 */
    int fd[2];
    /** 파이프 라인 생성 및 생성 실패 시 조건문 */
    if (pipe(fd) < 0) {
        printf("pipe lien create failed...\r\n");
        exit(1);
    }
    /** pipe 에 전달 */
    write(fd[1], msg1, MSGSIZE);
    write(fd[1], msg2, MSGSIZE);
    write(fd[1], msg3, MSGSIZE);
    /** 한번씩 pipe 에 있는 값 읽어 오기 */
//    for (size_t i = 0; i < 3; i++) {
//        read(fd[0], inBuf, sizeof inBuf);
//        printf("read msg %zu : [%s]\r\n", i, inBuf);
//    }
    /** 파이프 라인을 통해서 한번에 읽어오기 */
    ret = read(fd[0], inBuf, sizeof inBuf);
    printf("read ret : %d\r\n", ret);
    /** 한번에 값을 읽어오기 */
    write(1, inBuf, ret);
    printf("\r\n");

    return 0;
}
