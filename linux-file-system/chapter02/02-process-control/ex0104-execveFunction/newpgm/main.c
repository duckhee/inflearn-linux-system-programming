#include <stdio.h>

/** main 함수는 인자만 받아오는 것이 아니라 환경 변수도 인자로 받을 수 있다.*/
int main(int argc, char **argv, char **envp) {
    size_t i;
    for (i = 0; i < argc; ++i)
        printf("argv[%d] = %s\r\n", i, argv[i]);
    printf("------------------------------\r\n");
    /** envp 가 NULL 이 될 때 까지 반복문 실행 */
    for (i = 0; envp[i]; ++i)
        printf("envp[%d] = %s\r\n", i, envp[i]);
    return 0;
}
