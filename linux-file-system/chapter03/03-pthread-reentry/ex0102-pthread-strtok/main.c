#include <stdio.h>
#include <string.h>
#include <pthread.h>

void *my_handler(void *);
void *ip_filter(void *);

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

/**
 *
 * 문자게 생기는 이유가 strtok 함수 안에서 static pointer 로 진행을 하기 때문에
 * pointer 의 주소 값이 계속 해서 변경이 되므로 parsing에 간섭이 문제가 생긴다.
 * => lock 을 이용해서 해결을 할려고 해도 동시에 parsing 하는 부분에서 문제가 생긴다.
 * thread 로 동작하는 것은 동시성에 대해 지원을 해야한다.
 */
int main(void) {
    /** thread 식별자를 저장하기 위한 구조체 */
    pthread_t thread;
    pthread_t ipThread;
    /** thread 생성 */
    pthread_create(&thread, NULL, my_handler, NULL);
    pthread_create(&ipThread, NULL, ip_filter, NULL);
    /** thread 종료될 때까지 대기 */
    pthread_join(thread, NULL);
    pthread_join(ipThread, NULL);
    return 0;
}

void *my_handler(void *data) {
    char hp[] = "010-1234-5678";
    /** 잘라진 문자열을 받기 위한 포인터 변수 */
    char *p;
    /** static 변수를 사용하지 않기 위해서 mutex_lock을 이용한 처리 */
    pthread_mutex_lock(&mutex);
    /** 문자열 자르기 */
    p = strtok(hp, "-");
    /** 더 이상 자를 문자열이 없을 때 까지 진행하는 반복문 */
    while (p) {
        printf("[%s]\r\n", p);
        /** 문자열에 대한 정보를 NULL 로 넣어야 다음 위치로 이동하면서 잘라낸다. */
        p = strtok(NULL, "-");
    }
    /** static 변수 사용이 끝났으므로 lock 해제 */
    pthread_mutex_unlock(&mutex);
}

void *ip_filter(void *data){
    char ip[] = "127.0.0.1";
    /** 잘라진 문자열을 받기 위한 포인터 변수 */
    char *p;
    /** static 변수를 사용하지 않기 위해서 mutex_lock을 이용한 처리 */
    pthread_mutex_lock(&mutex);
    /** 문자열 자르기 */
    p = strtok(ip, ".");
    /** 더 이상 자를 문자열이 없을 때 까지 진행하는 반복문 */
    while (p) {
        printf("[%s]\r\n", p);
        /** 문자열에 대한 정보를 NULL 로 넣어야 다음 위치로 이동하면서 잘라낸다. */
        p = strtok(NULL, ".");
    }
    /** static 변수 사용이 끝났으므로 lock 해제 */
    pthread_mutex_unlock(&mutex);
}
