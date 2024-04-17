#include <stdio.h>
#include <string.h>

int main(void) {
    char hp[] = "010-1234-5678";
    char *p;
    /** 문자열 형태를 자를 때 사용하는 함수이다. -> 특정 문자열에 대한 값으로 해당 배열에서 나누어서 반환을 한다. */
    p = strtok(hp, "-");
    while (p) {
        printf("[%s]\r\n", p);
        /** null pointer 로 넘겨주면 다음 문자열에서 값을 찾는다. -> 첫번째부터 찾는 형태가 아니라 다음 위치 부터 값을 찾는 형태이다. */
        p = strtok(NULL, "-");
    }

    return 0;
}
