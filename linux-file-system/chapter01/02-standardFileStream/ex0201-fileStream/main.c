#include <stdio.h>

#define BUFFER_MAX      1024

int main(int argc, char **argv) {
    char buffer[BUFFER_MAX];
    int ret;
    /** 표준 입력을 받은 값을 buffer에 값을 담아준다. */
    while (fgets(buffer, sizeof buffer, stdin))
        /** 가져온 값을 buffer 에 담아둔 것을 출력한다.*/
        fputs(buffer, stdout);
    return 0;
}