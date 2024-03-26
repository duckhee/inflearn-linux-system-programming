#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <dirent.h>

/** 현재 폴더에서 순회하면서 파일 목록을 출력하는 함수 */
void my_ls(const char *pDireName);

int main(int argc, char **argv) {
    my_ls(".");
    return 0;
}

/** 현재 폴더에서 순회하면서 파일 목록을 출력하는 함수 */
void my_ls(const char *pDireName) {
    /** 폴더에 대한 객체를 담을 포인터 */
    DIR *pDir = NULL;
    /** Directory 내부에 있는 정보를 담고 있는 객체 */
    struct dirent *pDirent = NULL;
    /** 해당 폴더의 위치로 이동하는 함수 */
    chdir(pDireName);
    /** 현재 위치의 폴더 열기 */
    pDir = opendir(".");
    /** 해당 directory 에 대한 정보 읽어와서 순회 */
    while ((pDirent = readdir(pDir))) {
        /** file 에 대한 정보 출력 */
        printf("%s\r\n", pDirent->d_name);
    }
    /** directory resource 반환 */
    closedir(pDir);
    /** 상위 폴더 위치로 이동 */
    chdir("..");
}
