#include <unistd.h>

int main(int argc, char **argv) {
    /** 환경 변수에 정의된 곳에 있는 경로를 기본으로 가져오기 때문에 전체 경로를 쓰지 않고 프로세스의 이름만 넣어주면 실행이 되는 함수이다. */
    execlp("ls", "ls", "-l", NULL);
    return 0;
}
