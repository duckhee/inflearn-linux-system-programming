#include <stdio.h>
#include <unistd.h>

int main(void) {
    int seconds;
    char line[128];
    char message[65];
    /** 알림에 대한 반복을 하기 위한 반복문 */
    while (1) {
        /** prompt */
        printf("Alarm > ");
        /** input */
        fgets(line, sizeof line, stdin);
        /** 파싱하기 위한 함수 -> 입력 받은 버퍼에 있는 값의 특정 형태에 따라 맞게 해당 값을 찾아서 인자로 받은 변수에 값을 넣어주는 역활을 하는 함수이다. */
        //    sscanf(line, "%d %s", &seconds, message);
        /** 문자열을 64개까지 받을 수 있으면서 엔터 값이 나오기 전까지 입력을 받는 것을 의미하는 것이 %64[^\n] 형식이다. */
        sscanf(line, "%d %64[^\n]", &seconds, message);

        /** 입력 받은 숫자만큼 대기 */
        sleep(seconds);
        /** 입력 받은 메세지 출력 */
        printf("(%d) %s\r\n", seconds, message);
    }
    return 0;
}
