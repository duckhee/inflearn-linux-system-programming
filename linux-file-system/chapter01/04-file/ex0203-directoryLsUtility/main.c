#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>
#include <dirent.h>
#include <string.h>

void my_ls(const char *pDireName);

int main(int argc, char **argv) {
    my_ls(".");
    return 0;
}

void my_ls(const char *pDireName) {
    /** directory 구조를 가져오기 위한 pointer */
    DIR *pDir = NULL;
    /** directory 에 대한 정보를 담기 위한 pointer */
    struct dirent *pDirent = NULL;
    /** 상태에 대한 값을 저장하기 위한 구조체 */
    struct stat tempStat = {0,};
    /** 입력 받은 directory 로 들어가기 */
    chdir(pDireName);
    /** 현재 directory 열기 */
    pDir = opendir(".");
    /** 열어져 있는 directory 안에 있는 파일 정보 가져오기 위한 순회 */
    while ((pDirent = readdir(pDir))) {
        /** 해당 폴더에 대한 정보를 가져오기 */
        lstat(pDirent->d_name, &tempStat);

        printf("%s \r\n", pDirent->d_name);
        /** sub directory 가 있을 경우 */
        if (S_ISDIR(tempStat.st_mode)) {
            /** 현재 directory 와 상위 directory 를 나타내는 경우 제외한 경우 -> strcmp 는 두 값이 같을 경우 0 반환 */
            if (strcmp(pDirent->d_name, ".") && strcmp(pDirent->d_name, "..")) {
                /** 재귀 호출 */
                my_ls(pDirent->d_name);
            }
        }
    }
    /** DIR 반환 */
    closedir(pDir);
    /** 상위 폴더로 이동 */
    chdir("..");
}
