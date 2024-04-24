#include <stdio.h>

#define MAX_BUF_SIZE            1024

int main(void) {
    /** 파일에 대한 값을 저장하기 위한 파일 구조체 */
    FILE *pipein_fp, *pipeout_fp;
    /** 출력을 위한 임시 버퍼 */
    char readBuffer[MAX_BUF_SIZE];
    /** popen 을 통해서 파이프를 읽기 전용만 남긴다는 의미이다. */
    pipein_fp = popen("ls", "r");
    /** popen을 통해서 파이플 쓰기 전용만 남긴다는 의미이다. */
    pipeout_fp = popen("sort", "w");
    /** 읽기 전용의 파이프 라인에 있는 값을 읽어서 출력 하는 반복문 */
    while (fgets(readBuffer, MAX_BUF_SIZE, pipein_fp)) {
        fputs(readBuffer, pipeout_fp);
    }
    /** 파이프를 당아준다. */
    pclose(pipein_fp);
    pclose(pipeout_fp );
    return 0;
}
