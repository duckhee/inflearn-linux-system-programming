#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
/** directory 에 대한 정보를 가져오기 위한 header */
#include <dirent.h>

int main(int argc, char **argv) {
    /** directory 에 대한 구조체를 가르키기 위한 포인터 */
    DIR *pDir = NULL;
    /** directory 에 대한 정보를 가져오기 위한 pointer */
    struct dirent *pDirent = NULL;
    /** 현재 directory를 열기 위한 경로 */
    pDir = opendir(".");
    /** 반복해서 directory 에 있는 파일에 대한 정보를 얻기 위한 반복문 */
    while (pDirent = readdir(pDir)) {
        /** 파일에 대한 정보를 가져오는 함수 */
//        pDirent = readdir(pDir);
        printf("%s \r\n", pDirent->d_name);
    }
    /** directory 닫기 */
    closedir(pDir);
    return 0;
}
