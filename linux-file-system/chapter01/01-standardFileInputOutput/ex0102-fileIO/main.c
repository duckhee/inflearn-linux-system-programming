#include <stdio.h>

int main() {
    FILE *fp;
    int ch;
    int i;
    fp = fopen("main.c", "r");
    if (fp == NULL) {
        printf("File Open Failed...\r\n");
        return -1;
    }
    /** 파일의 끝 부분이 아닐 때까지 읽어오기 위한 반복문 => 비교 우선 순위가 높으므로 대입 연산에 대한 우선순위를 ()를 이용해서 우선 순위를 올려준다. */
    while ((ch = fgetc(fp)) != EOF) {
        fputc(ch, stdout);
    }
    fclose(fp);
    return 0;
}