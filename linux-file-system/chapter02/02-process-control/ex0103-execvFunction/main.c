#include <stdio.h>
#include <unistd.h>

int main(void) {
    char *lsArgv[] = {"ls","-l", NULL};
    /** 싫행 시킬 프로그램의 파일 경로와 넘겨줄 인자를 배열 형태로 넣어주면 핻아 프로그램에 인자를 넣어서 실행을 시켜준다. */
    execv("/bin/ls", lsArgv);
    return 0;
}
