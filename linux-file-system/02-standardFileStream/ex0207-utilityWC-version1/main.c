#include <stdio.h>

int main(int argc, char **argv) {
    FILE *fp;
    int ch;
    int flag = 0;
    int counter[3] = {0,};
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("file open failed...\r\n");
        return -1;
    }
    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            counter[0]++;
        }
        if (ch != '\n' && ch != ' ' && ch != '\t') {
            if (flag == 0) {
                counter[1]++;
                flag = 1;
            }
        } else {
            flag = 0;
        }
        counter[2]++;
    }
//    printf("file name : %s, line number : %d, word number : %d, word number : %d\r\n", argv[1], counter[0], counter[2],
//           counter[1]);
    printf("%4d %4d %4d %s\r\n", counter[0], counter[1], counter[2], argv[1]);
    fclose(fp);
    return 0;
}