#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    /** 자식 프로세스 pid 와 pipe 의 file descriptor 를 저장하기 위한 변수 */
    int fd[2], pid;
    /** pipe 생성 및 에러 발생 시 조건문 */
    if (pipe(fd) == -1) {
        perror("pipe()");
        exit(1);
    }
    /** 자식 프로세스 동작 */
    if ((pid = fork()) == 0) {
        /** pipe 의 쓰기 파일 닫기 */
        close(fd[1]);
        /** file descriptor 를 연결 -> 출력과 파이프 읽기를 연결 */
        dup2(fd[0], 0);
        /** 프로그램을 등록된 경로에서 찾아서 실행 */
        execlp(argv[2], argv[2], (char *) 0);
    }
    /** 읽기에 대한 파일 닫기 */
    close(fd[0]);
    /** file descriptor 를 연결 -> 입력과 파이프 쓰기를 연결 */
    dup2(fd[1], 1);
    /** 프로그램을 등록된 경로에서 찾아서 실행 */
    execlp(argv[1], argv[1], NULL);
    return 0;
}
