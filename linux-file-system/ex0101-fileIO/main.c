#include <stdio.h>

int main() {
    /** file의 다루기 위한 file pointer */
    FILE *fp;
    /** 파일의 한 바이트를 가져와서 읽기 위한 변수 */
    int ch;
    /** file 을 읽기 모드로 열기 */
    fp = fopen("main.c", "r");
    if (fp == NULL) {
        printf("File Open Failed...\r\n");
        return -1;
    }
    ch = fgetc(fp);
    fputc(ch, stdout);
    /** file 닫아 주기 */
    fclose(fp);

    return 0;
}