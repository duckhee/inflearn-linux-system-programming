#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

typedef struct _Alarm_tag {
    int seconds;
    char message[65];
} alarm_t;

/** 알람 thread 에서 동작할 함수 */
void *alarm_routine(void *);

int main(void) {
    /** 입력에 대한 임시 저장을 위한 버퍼 */
    char lines[128];
    /** thread 생성을 위한 변수 */
    pthread_t thread;
    /** 알림 값을 가져오기 위한 구조체 변수 */
    alarm_t *customAlarm;
    while (true) {
        /** 동적 메모리 할당 */
        customAlarm = calloc(1, sizeof(alarm_t));
        /** promt */
        printf("Alarm > ");
        /** terminal console 로 입력 받기 */
        fgets(lines, sizeof lines, stdin);
        sscanf(lines, "%d %64[^\n]", &customAlarm->seconds, customAlarm->message);
        pthread_create(&thread, NULL, alarm_routine, customAlarm);
    }

    return 0;
}

void *alarm_routine(void *arg) {
    alarm_t *getAlarm = (alarm_t *) arg;
    /** 독립적으로 동작하기 위해서 분리하기 위한 함수 */
    /** 자기 자신에 대한 정보를 확인하기 위해서 사용하는 함수가 pthread_self() 이다. */
    pthread_detach(pthread_self());
    sleep(getAlarm->seconds);
    printf("(%d) %s\r\n", getAlarm->seconds, getAlarm->message);
    /** 동적 메모리에 대한 해제 */
    free(getAlarm);
    /** 자동적으로 파괴가 된다.*/
    return (void *) 0;
}

