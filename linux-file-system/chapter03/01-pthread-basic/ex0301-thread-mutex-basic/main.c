#include <stdio.h>
#include <pthread.h>


int g_sum = 0;

/** 동기화 형태로 사용하기 위한 mutex 에 대한 객체 선언 */
pthread_mutex_t mutex;
/** 프포개르매가 직접 초기화한다면 다음과 같이 초기화를 하면 된다. -> 선언과 동시에 초기화를 하는 코드이다. */
//pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

/** thread 가 동작할 행위에 대한 저장한 함수 */
void *sub_routine(void *);

int main(void) {
    /** Thread 에 대한 정보를 가지고 있는 배열 변수 */
    pthread_t thread[2];
    /** mutex 를 사용하기 위한 초기화 */
    pthread_mutex_init(&mutex, 0);
    /** thread 생성하는 함수 */
    pthread_create(&thread[0], 0, sub_routine, 0);
    pthread_create(&thread[1], 0, sub_routine, 0);

    /** thread 가 종료가 될 때 까지 대기하는 함수 process 의 wait 함수와 동일한 기능을 한다. */
    pthread_join(thread[0], 0);
    pthread_join(thread[1], 0);
    printf("sum value : %d \r\n", g_sum);
    return 0;
}

/** thread 가 동작할 행위에 대한 저장한 함수 */
void *sub_routine(void *threadArg) {
    int local;
    size_t i;
    /** 동기화 문제로 인해 제대로된 값의 덧셈이 일어나지 않는다. */
    for (i = 0; i < 10000000; ++i) {
        /** 동기화를 위해서 mutex에 대한 lock 을 걸어줘야한다. */
        pthread_mutex_lock(&mutex);
        local = g_sum;
        local = local + 1;
        g_sum = local;
        /** 동기화 코드에 대한 실행이 끝나면 lock 에 대한 해제를 해줘야 다른 thread 에서 해당 변수에 대한 접근이 가능하게 된다. */
        pthread_mutex_unlock(&mutex);
    }
    return 0;
}
