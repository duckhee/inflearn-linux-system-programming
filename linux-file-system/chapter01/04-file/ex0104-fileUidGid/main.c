#include <stdio.h>
#include <sys/stat.h>

#include <sys/types.h>
/**  파일에 대한 사용자 권한에 대해서 정의가 되어 있는 파일에서 권한에 대한 정보를 보기 쉽게 하기 위해서 사용하는 함수의 header */
#include <pwd.h>
/**  파일에 대한 그룹 권한에 대해서 정의가 되어 있는 파일에서 권한에 대한 정보를 보기 쉽게 하기 위해서 사용하는 함수의 header */
#include <grp.h>


int main(int argc, char **argv) {
    /** 파일에 대한 정보를 저장하기 위한 구조체 */
    struct stat fileInformation = {0,};
    /** 파일에 대한 소유자 권한에 대한 정보를 손쉽게 얻기 위한 객체 */
    struct passwd *pwd = NULL;
    /** 파일에 대한 그룹 권한에 대한 정보를 손쉽게 얻기 위한 객체 */
    struct group *grp = NULL;
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
    stat(argv[1], &fileInformation);
    /** file type 에 따른 출력 */
    /** directory file */
    if (S_ISCHR(fileInformation.st_mode)) {
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
    printf("%lu ", fileInformation.st_size);
    printf("%s\r\n", argv[1]);
    return 0;
}
