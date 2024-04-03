#include <unistd.h>

int main(void) {
    /** 프로세스에 넘겨줄 인자의 배열 */
    char *argument[] = {"newpgm", "one", "two", (char *) 0};
    /** 프로세스에 넘겨줄 환경 변수 배열 */
    char *env[] = {"name=LG", "addr=seoul", NULL};
    /** 프로세스에 인자와 환경 변수를 넘겨줘서 실행하는 함수이다. */
    execve("./newpgm/buildDir/newpgm", argument, env);
    return 0;
}
