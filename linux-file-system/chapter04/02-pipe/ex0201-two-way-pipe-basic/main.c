#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <err.h>

#define MAX_BUF_SIZE                1024

void client(int read_fd, int write_fd);

void server(int read_fd, int write_fd);

int main(void) {
    /** 자식 프로세스를 저장하기 위한 변수 */
    int child_pid;
    /** pipe 에 대한 file descriptor 를 저장하기 위한 배열 */
    int pipe1[2], pipe2[2];
    /** 파이프 생성 */
    if (pipe(pipe1) < 0 || pipe(pipe2) < 0) {
        perror("pipe create error \r\n");
        exit(1);
    }
    /** process 생성 */
    child_pid = fork();
    /** 부모 프로세스 동작 */
    if (child_pid > 0) {
        /** pipe 읽기 file descriptor 닫기 */
        close(pipe1[0]);
        /** pipe 쓰기 file descriptor 닫기 */
        close(pipe2[1]);
        client(pipe2[0], pipe1[1]);
        while (wait((int *) 0) != child_pid) { ;
        }
        /** pipe 쓰기 file descriptor 닫기 */
        close(pipe1[1]);
        /** pipe 읽기 file descriptor 닫기 */
        close(pipe2[0]);
    }
        /** 자식 프로세스 동작 */
    else {
        /** pipe 쓰기 file descriptor 닫기 */
        close(pipe1[1]);
        /** pipe 읽기 file descriptor 닫기 */
        close(pipe2[0]);
        server(pipe1[0], pipe2[1]);
        /** pipe 읽기 file descriptor 닫기 */
        close(pipe1[0]);
        /** pipe 쓰기 file descriptor 닫기 */
        close(pipe2[1]);
    }
    return 0;
}

void client(int read_fd, int write_fd) {
    /** 버퍼 생성 -> 읽어온 값을 임시 저장하기 위한 버퍼 */
    char buffer[MAX_BUF_SIZE];
    /** 읽어온 문자열의 길이를 저장하기 위한 변수 */
    int n;
    /** buffer 의 초기화 */
    memset(buffer, '\0', sizeof buffer);
    /** 표준 입력의 값을 읽어오기 위한 조건문 -> 읽어오지 못했을 때 조건 */
    if (fgets(buffer, MAX_BUF_SIZE, stdin) == NULL) {
        printf("client : filename read error\r\n");
    }
    /** 읽어온 문자열의 길이 변수 대입 */
    n = strlen(buffer);
    /** buffer 의 끝이 enter 인 경우 */
    if (buffer[n - 1] == '\n') {
        n--;
    }
    /** pipe 에 읽어온 문자열을 전달하는 함수 -> 전달한 문자열의 길이가 일치 하지 않는 경우 */
    if (write(write_fd, buffer, n) != n) {
        printf("client : filename write error\r\n");
    }
    /** 읽어올 값이 있을 경우 반복해서 값 읽어오기 */
    while ((n = read(read_fd, buffer, MAX_BUF_SIZE)) > 0) {
        /** 표준 출력에 쓰기 위한 조건문 -> 문자열의 길이만큼 쓰지 못했을 때 조건문 */
        if (write(1, buffer, n) != n) {
            printf("client : data write error\r\n");
        }
    }
    /** 읽어온 값이 없을 경우 조건문 */
    if (n < 0) {
        printf("client : data read error\r\n");
    }
}

void server(int read_fd, int write_fd) {
    /** 버퍼 생성 -> 읽어온 값을 임시 저장하기 위한 버퍼 */
    char buffer[MAX_BUF_SIZE];
    /** buffer 의 초기화 */
    memset(buffer, '\0', sizeof buffer);
    /** 문자의 길이 및 file descriptor 를 저장하기 위한 변수 */
    int n, fd;
    /** 에러의 값을 가져오기 위한 extern 변수 */
    extern int errno;
    /** 읽어오지 못했을 경우 */
    if ((n = read(read_fd, buffer, MAX_BUF_SIZE)) <= 0) {
        printf("server : filename read error\r\n");
    }
    /** buffer 에 저장된 문자의 끝을 NULL 로 설정 */
    buffer[n] = '\0';
    /** buffer 에 대한 사용을 위해서 연결 했을 때 오류 발생 시 -> 입력된 파일 이름을 가지고 파일 열기 */
    if ((fd = open(buffer, 0)) < 0) {
        strcat(buffer, "can't open\r\n");
        /** 전달할 문자열의 길이를 가져오기 */
        n = strlen(buffer);
        /** error 메세지 전달할 때 에러 발생 했을 경우 */
        if (write(write_fd, buffer, n) != n) {
            printf("server : errmsg write error\r\n");
        }
    }
        /** 파일 열어서 읽어오기 */
    else {
        /** 데이터 읽어오기 */
        while ((n = read(fd, buffer, MAX_BUF_SIZE)) > 0) {
            /** 데이터 전송 실패시 */
            if (write(write_fd, buffer, n) != n) {
                printf("server : data write error\r\n");
            }
        }
    }
}
