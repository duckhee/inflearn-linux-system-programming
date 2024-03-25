#include <stdio.h>
#include <sys/stat.h>

void getFileInfo(const struct stat *file, char *permission);

void getFilePermission(const struct stat *file, char *permission);

int main(int argc, char **argv) {
    struct stat fileState = {0,};
    char permission[11] = "----------";
    /** 일반 권한에 대한 값 */
    char rwx[] = "rwx";
    /** 특수 권한에 대한 값 */
    char sst[] = "sst";
    /** file 에 대한 정보를 가져 오는 함수 */
    stat(argv[1], &fileState);
    /** file type 에 따른 출력 */
    /** basic file type */
//    if (S_ISREG(fileState.st_mode)) {
//        permission[0] = '-';
//    }
    /** directory file */
    if (S_ISDIR(fileState.st_mode)) {
        permission[0] = 'd';
    }
        /** character block file */
    else if (S_ISCHR(fileState.st_mode)) {
        permission[0] = 'c';
    }
        /** block file */
    else if (S_ISBLK(fileState.st_mode)) {
        permission[0] = 'b';
    }
        /** fifo file */
    else if (S_ISFIFO(fileState.st_mode)) {
        permission[0] = 'p';
    }
        /** symbolic file */
    else if (S_ISLNK(fileState.st_mode)) {
        permission[0] = 'l';
    }
        /** socket file */
    else if (S_ISSOCK(fileState.st_mode)) {
        permission[0] = 's';
    }
    /** permission -> basic permission */
    for (size_t i = 0; i < 9; ++i) {
        /** permission checking -> owner, group, other */
        if ((fileState.st_mode >> (8 - i)) & 0x1) {
            /** permission checking read, write, execute */
            permission[1 + i] = rwx[i % 3];
        }
    }
    /** special permission -> sst */
    for (size_t i = 0; i < 3; ++i) {
        /** check special permission */
        if ((fileState.st_mode >> (11 - i)) & 0x1) {
            /** checking read, write, execute check special permission */
            if (permission[(i + 1) * 3] == '-') {
                permission[(i + 1) * 3] = sst[i] - ('a' - 'A');
            } else {
                permission[(i + 1) * 3] = sst[i];
            }
        }
    }
//    getFileInfo(&fileState, permission);
//    getFilePermission(&fileState, permission);
    printf("%s ", permission);
    /** 현재 파일이 연결이 되어 있는 파일의 갯수 -> mac unsigned short */
    printf("%hu ", fileState.st_nlink);
    /** 파일에 대한 소유자 정보 -> unsigned int */
    printf("%u ", fileState.st_uid);
    /** 파일에 대한 소유 그룹의 정보 -> unsigned int */
    printf("%u ", fileState.st_gid);
    printf("%s\r\n", argv[1]);
    return 0;
}

void getFileInfo(const struct stat *file, char *permission) {
    /** file type 에 따른 출력 */
    /** basic file type */
//    if (S_ISREG(fileState.st_mode)) {
//        permission[0] = '-';
//    }
    /** directory file */
    if (S_ISCHR(file->st_mode)) {
        permission[0] = 'd';
    }
        /** character block file */
    else if (S_ISCHR(file->st_mode)) {
        permission[0] = 'c';
    }
        /** block file */
    else if (S_ISBLK(file->st_mode)) {
        permission[0] = 'b';
    }
        /** fifo file */
    else if (S_ISFIFO(file->st_mode)) {
        permission[0] = 'p';
    }
        /** symbolic file */
    else if (S_ISLNK(file->st_mode)) {
        permission[0] = 'l';
    }
        /** socket file */
    else if (S_ISSOCK(file->st_mode)) {
        permission[0] = 's';
    }
}

void getFilePermission(const struct stat *file, char *permission) {
    char rwx[] = "rwx";
    char sst[] = "sst";
    /** permission -> basic permission */
    for (size_t i = 0; i < 9; ++i) {
        /** permission checking -> owner, group, other */
        if ((file->st_mode >> (8 - i)) & 0x1) {
            /** permission checking read, write, execute */
            permission[1 + i] = rwx[i % 3];
        }
    }
    /** special permission -> sst */
    for (size_t i = 0; i < 3; ++i) {
        /** check special permission */
        if ((file->st_mode >> (11 - i)) & 0x1) {
            /** checking read, write, execute check special permission */
            if (permission[(i + 1) * 3] == '-') {
                permission[(i + 1) * 3] = sst[i] - ('a' - 'A');
            } else {
                permission[(i + 1) * 3] = sst[i];
            }
        }
    }
}