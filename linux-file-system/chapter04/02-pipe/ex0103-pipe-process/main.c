#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MSG_SIZE        20


int main(void) {
    /** 자식 프로세스와 pipe 의 file descriptor 를 저장하기 위한 변수 */
    int fd[2], pid;
    /** 전달할 message */
    char msgout[MSG_SIZE] = "Hello, world\n";
    /** 전달 받은 값을 저장하기 위한 buffer */
    char msgIn[MSG_SIZE];
    /** pipe 생성 */
    if (pipe(fd) == -1) {
        /** error 출력 */
        perror("pipe()");
        /** 프로그램 종료 */
        exit(1);
    }
    /** 부모 프로세스가 동작하는 코드 */
    if ((pid = fork()) > 0) {
        /** 읽기 전용의 pipe 에 대한 파일 닫아 주기 */
        close(fd[0]);
        /** 쓰기 전용 pipe 에 쓰기 */
        write(fd[1], msgout, MSG_SIZE);
    }
    
        /** 자식 프로세스 생성 및 자식 프로세스 동작 */
    else if (pid == 0) {
        /** pipe 의 쓰기용 파일 닫기 */
        close(fd[1]);
        /** 동기적으로 값을 읽어오기 */
        read(fd[0], msgIn, MSG_SIZE);
        /** 읽어온 값 출력 */
        puts(msgIn);
    }
        /** 에러 발생 시 동작 */
    else {
        perror("fork()");
        exit(2);
    }
    return 0;
}
