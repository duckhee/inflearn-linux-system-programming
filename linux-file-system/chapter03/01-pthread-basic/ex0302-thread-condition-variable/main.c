#include <stdio.h>
#include <unistd.h>
#include <pthread.h>


/** conditional variable 은 mutex 와 사용이 되기 때문에 전역 변수의 값이 동기화된 상태로 사용이 된다. */
int g_flag = 0;

/** 동기화 이슈를 제거하기 위한 mutex */
pthread_mutex_t mutex;
/** mutex 선언 및 초기화 */
//pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
/** thread에게 신호를 보내주기 위한 객체 */
pthread_cond_t cond;
/** conditional variable 선언 및 초기화 */
//pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

/** event 를 발행 시키는 Thread */
void *producer(void *);

/** event 가 밿행 되었을 때 동작하기 위한 thread */
void *consumer(void *);

int main(void) {
    /** thread 를 담고 있기 위한 객체 배열 */
    pthread_t thread[2];
    /** 임계 영역에 대한 동기화 이슈를 제어하기 위한 mutex 초기화 */
    pthread_mutex_init(&mutex, NULL);
    /** thread 간 통신을 위한 conditional variable 초기화 */
    pthread_cond_init(&cond, NULL);
    /** thread 생성 */
    pthread_create(&thread[0], NULL, producer, NULL);
    pthread_create(&thread[1], NULL, consumer, NULL);
    /** thread 종료까지 대기하기 위한 함수 */
    pthread_join(thread[0], NULL);
    pthread_join(thread[1], NULL);

    /** mutex 변수 해제 */
    pthread_mutex_destroy(&mutex);
    /** cond 변수 해제 */
    pthread_cond_destroy(&cond);

    return 0;
}

void *producer(void *data) {
    /** 전역 변수에 대한 동기화 이슈를 제거하기 위한 mutex lock */
    pthread_mutex_lock(&mutex);
    /** 대기 후 동작을 하는지 확인하기 위한 대기 */
    sleep(3);
    printf("decoding end\r\n");
    /** conditional variable 전역변수에 대한 mutex 접근에 대한 상태를 확인하기 위한 변경 */
    g_flag = 10;
    /** 타 thread에게 신호를 주기 위한 객체 */
    pthread_cond_signal(&cond);
    /** 작업이 완료된 후에 mutex lock 에 대한 반환 하는 함수 */
    pthread_mutex_unlock(&mutex);
    return 0;
}

void *consumer(void *data) {
    /** 전역 변수에 대한 동기화 이슈를 제거하기 위한 mutex lock */
//    pthread_mutex_lock(&mutex);
    /** conditional variable 에 대한 대기하기 위한 함수 */
    pthread_cond_wait(&cond, &mutex);
    printf("play flag : %d\r\n", g_flag);
    /** 작업이 완료된 후에 mutex lock 에 대한 반환 하는 함수 */
    pthread_mutex_unlock(&mutex);
    return 0;
}
