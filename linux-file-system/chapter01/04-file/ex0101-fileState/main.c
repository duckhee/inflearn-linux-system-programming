#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char **argv) {
    struct stat fileState;
    char *ptr = NULL;
    /** 입력 받은 인자의 숫자 만큼 반복하기 위한 반복문 */
    for (int i = 1; i < argc; ++i) {
        /** 입력 받은 인자의 이름 출력 */
        printf("%s : ", argv[i]);
        /** file state 를 가져오기 위한 함수 */
        stat(argv[i], &fileState);
        if (S_ISREG(fileState.st_mode)) {
            ptr = "regular";
        }
            /** 해당 파일이 폴더일 경우 */
        else if (S_ISDIR(fileState.st_mode)) {
            ptr = "directory";
        }
            /** character block */
        else if (S_ISCHR(fileState.st_mode)) {
            ptr = "character special";
        }
            /** block */
        else if (S_ISBLK(fileState.st_mode)) {
            ptr = "block special";
        }
            /** first in first out buffer */
        else if (S_ISFIFO(fileState.st_mode)) {
            ptr = "fifo";
        }
            /** symbolic link */
        else if (S_ISLNK(fileState.st_mode)) {
            ptr = "symbolic link";
        }
            /** socket */
        else if (S_ISSOCK(fileState.st_mode)) {
            ptr = "socket";
        }
            /** not found mode */
        else {
            ptr = "** unknown mode **";
        }
        printf("%s\r\n", ptr);
    }
    return 0;
}