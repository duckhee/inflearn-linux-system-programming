#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv) {
    FILE *fp;
    int ch;
    int i;
    fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("file open failed...\r\n");
        return -1;
    }
    while ((ch = fgetc(fp)) != EOF) {
        usleep(100000);
        fputc(ch, stdout);
        fflush(stdout);
    }
    fclose(fp);
    printf("\r\n");
    return 0;
}