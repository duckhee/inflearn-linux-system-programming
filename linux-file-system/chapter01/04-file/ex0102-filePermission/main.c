#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv) {
    struct stat fileState;
    char perm[11] = "----------";
    char rwx[] = "rwx";
    /** 특수 권한에 대해서 나타내기 위한 배열 */
    char sst[] = "sst";
    stat(argv[1], &fileState);

    /** 해당 비트를 오른쪽으로 이동 시키면서 권한에 대해서 확인하기 위한 조건 문 */
    for (int i = 0; i < 9; ++i) {
        if ((fileState.st_mode >> (8 - i)) & 0x1) {
            perm[1 + i] = rwx[i % 3];
        }
    }
    /** 특수 권한에 대해서 표시하기 위한 반복문 */
    for (int i = 0; i < 3; ++i) {
        /** 특수 권한에 대해서 확인 */
        if ((fileState.st_mode >> (11 - i)) & 0x1) {
            /** 특수 권한의 표시가 소문자로 표현 */
            if (perm[(i + 1) * 3] == '-') {
                /** 대문자와 소문자는 32 만큼 차이가 나므로 빼주면 대문자를 나타낸다.*/
                perm[(i + 1) * 3] = sst[i] - ('a' - 'A');
            } else {
                perm[(i + 1) * 3] = sst[i];
            }
        }
    }
    printf("%s\r\n", perm);;
    return 0;
}