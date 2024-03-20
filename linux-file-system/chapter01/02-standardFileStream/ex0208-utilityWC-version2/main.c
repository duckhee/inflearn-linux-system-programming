#include <stdio.h>

int getWidth(int number);

int main(int argc, char **argv) {
    FILE *fp;
    int ch = 0;
    int flag = 0;
    int counter[3] = {0,};
    int width = 0;
    int w = 0;
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("File Open Failed...\r\n");
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
    for (int i = 0; i < 3; i++) {
        w = getWidth(counter[i]);
        if (width < w) {
            width = w;
        }
    }
    /** 동적으로 위치를 넣기 위해서는 printf 에서는 *를 사용하면 된다. */
    printf("width: %d\r\n", width);
    printf("%*d %*d %*d %s\r\n", width, counter[0], width, counter[1], width, counter[2], argv[1]);
    fclose(fp);
    return 0;
}

int getWidth(int number) {
    int i;
    for (i = 0; number != 0; i++) {
        number /= 10;
    }
    return i;
}