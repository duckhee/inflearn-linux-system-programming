#include <stdio.h>

int main(int argc, char **argv) {
    FILE *fp;
    int ch;
    int count = 0;
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("File Open Failed...\r\n");
        return -1;
    }
    /** 파일의 끝 부분이 아닐 때까지 읽어오기 위한 반복문 => 비교 우선 순위가 높으므로 대입 연산에 대한 우선순위를 ()를 이용해서 우선 순위를 올려준다. */
    while ((ch = fgetc(fp)) != EOF) {
//        fputc(ch, stdout);
        count++;
    }
    printf("file name : %s, size: %d\r\n", argv[1], count);
    fclose(fp);
    return 0;
}