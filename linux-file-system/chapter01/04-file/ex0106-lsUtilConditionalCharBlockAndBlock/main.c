#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <string.h>

int main(int argc, char **argv) {
    /** 파일에 대한 정보를 저장하기 위한 구조체 */
    struct stat fileInformation = {0,};
    /** 파일에 대한 소유자 권한에 대한 정보를 손쉽게 얻기 위한 객체 */
    struct passwd *pwd = NULL;
    /** 파일에 대한 그룹 권한에 대한 정보를 손쉽게 얻기 위한 객체 */
    struct group *grp = NULL;
    /** 수정 시간을 담기 위한 구조체 */
    struct tm *fileUpdateTime = NULL;
    /** permission 을 저장하기 위한 배열 */
    char permission[11] = "----------";
    /** 일반 권한에 대한 정보를 담고 있는 배열 */
    char rwx[] = "rwx";
    /** 특수 권한에 대한 정보를 담고 있는 배열 */
    char sst[] = "sst";

    if (argc != 2) {
        printf("usage: input file name \r\n");
        return -1;
    }
    /** 인자로 받은 값에서 파일 정보 가져오기 */
    /** link file 에 대한 정보를 가져오기 위한 stat 함수 */
    lstat(argv[1], &fileInformation);
    /** file type 에 따른 출력 */
    /** directory file */
    if (S_ISDIR(fileInformation.st_mode)) {
        permission[0] = 'd';
    }
        /** character block file */
    else if (S_ISCHR(fileInformation.st_mode)) {
        permission[0] = 'c';
    }
        /** block file */
    else if (S_ISBLK(fileInformation.st_mode)) {
        permission[0] = 'b';
    }
        /** fifo file */
    else if (S_ISFIFO(fileInformation.st_mode)) {
        permission[0] = 'p';
    }
        /** symbolic file */
    else if (S_ISLNK(fileInformation.st_mode)) {
        permission[0] = 'l';
    }
        /** socket file */
    else if (S_ISSOCK(fileInformation.st_mode)) {
        permission[0] = 's';
    }
    /** permission -> basic permission */
    for (size_t i = 0; i < 9; ++i) {
        /** permission checking -> owner, group, other */
        if ((fileInformation.st_mode >> (8 - i)) & 0x1) {
            /** permission checking read, write, execute */
            permission[1 + i] = rwx[i % 3];
        }
    }
    /** special permission -> sst */
    for (size_t i = 0; i < 3; ++i) {
        /** check special permission */
        if ((fileInformation.st_mode >> (11 - i)) & 0x1) {
            /** checking read, write, execute check special permission */
            if (permission[(i + 1) * 3] == '-') {
                permission[(i + 1) * 3] = sst[i] - ('a' - 'A');
            } else {
                permission[(i + 1) * 3] = sst[i];
            }
        }
    }
    printf("%s ", permission);
    /** 현재 파일이 연결이 되어 있는 파일의 갯수 -> mac unsigned short */
    printf("%hu ", fileInformation.st_nlink);
    /** 파일에 대한 소유자 정보 -> unsigned int */
//    printf("%u ", fileInformation.st_uid);
    /** get file uid */
    pwd = getpwuid(fileInformation.st_uid);
    printf("%s ", pwd->pw_name);
    /** 파일에 대한 소유 그룹의 정보 -> unsigned int */
//    printf("%u ", fileInformation.st_gid);
    grp = getgrgid(fileInformation.st_gid);
    printf("%s ", grp->gr_name);
    /** file 에 대한 사이즈 출력 */
    /** char block 과 block 은 사이즈 출력이 아니라 major 번호와 minor 번호를 찍어줘야한다.*/
    if (permission[0] == 'c' || permission[0] == 'b') {
        /** major 번호와 minor 번호를 읽어오는 코드 */
//        printf("version : %d, %d ", (fileInformation.st_rdev >> 8) & 0xFF, (fileInformation.st_rdev) & 0xFF);
        printf("%lu, %lu ", (fileInformation.st_rdev >> 8) & 0xff, fileInformation.st_rdev & 0xff);
    } else {
        printf("%llu ", fileInformation.st_size);
    }
    /** file 의 마지막 수정 시간을 출력 */
    /** mac에서는 st_mtime에 대한 정보를 구조체로 저장하고 있다.*/
    struct timespec timespec = fileInformation.st_mtimespec;
    /** linux에서는 st_mtime의 값이 mac 에서는 timespec의 tv_sec로 정의가 되어 있다. */
//    printf("%lu ", timespec.tv_sec);
    /** 흔히 보는 시간에 대한 format으로 변경하기 위해서 사용하는 함수가 ctime이다. -> default format 형태로만 출력한다. */
//    printf("%s", ctime(&timespec.tv_sec));

    fileUpdateTime = localtime(&timespec.tv_sec);
    /** tm_mon은 사용할 때 1을 더해줘야한다. -> index가 0부터 시작을 한다. */
//    printf("%s ", getMonthName(fileUpdateTime->tm_mon));
    printf("%d월 %d %d:%02d:%02d ", (fileUpdateTime->tm_mon + 1), fileUpdateTime->tm_mday, fileUpdateTime->tm_hour,
           fileUpdateTime->tm_min, fileUpdateTime->tm_sec);
    /** symbolic link */
    if (permission[0] == 'l') {
        /** 원본이 있는 위치를 출력 */
        char buffer[256];
        memset(buffer, '\0', sizeof buffer);
        /** symbolic link 원본 위치의 값을 읽어오기 */
        int ret = readlink(argv[1], buffer, sizeof buffer);
        buffer[ret] = '\0';
        printf("%s -> %s \r\n", argv[1], buffer);
    } else {
        printf("%s\r\n", argv[1]);
    }

    return 0;

    return 0;
}
