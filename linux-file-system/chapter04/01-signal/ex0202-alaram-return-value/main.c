#include <stdio.h>
#include <signal.h>
#include <unistd.h>

/** 알람 발생 시 동작할 handler 함수 */
void alarm_handler(int sigNo) {
    printf("alarm signal (%d)\r\n", sigNo);

}

int main(void) {
    /** 이전 알람의 남은 시간을 저장하기 위한 변수 */
    unsigned int remindAlarm;
    /** 알람 신호 시 동작할 handler 함수 등록 */
    signal(SIGALRM, alarm_handler);
    /** 처음 알람 신호 등록 */
    alarm(10);
    /** 3초 대기 */
    sleep(3);
    /** 알람 신호를 재 등록 -> 이전에 있던 알람의 남은 값을 반환 한다. */
    remindAlarm = alarm(3);
    printf("이전 알람의 남은 시간 : %u\r\n", remindAlarm);
    while (1);
    return 0;
}
