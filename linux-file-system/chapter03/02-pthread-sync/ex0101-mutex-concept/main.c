#include <pthread.h>
#include "customerror.h"


#define MAX_THREAD          (2)


typedef int int32_t;

/** assembler code 로 lock 구현 */
int __bionic_cmpxchg(int32_t old_value, int32_t new_value, volatile int32_t *ptr) {
    int32_t prev;
    __asm__ __volatile__ ("lock; cmpxchgl %1, %2"
            : "=a" (prev)
            : "q" (new_value), "m" (*ptr), "0" (old_value)
            : "memory"
            );
    return prev != old_value;
}

int g_sum = 0;
/** mutex 선언 및 초기화 */
//pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
/** mutex 와 비슷하게 동작하기 위한 flag */
int g_mutex = 0;

void *sub_routine(void *arg);

int main(void) {
    pthread_t thread[MAX_THREAD];
    size_t i;
    for (i = 0; i < MAX_THREAD; ++i) {
        pthread_create(thread[i], NULL, sub_routine, NULL);
    }

    for (i = 0; i < MAX_THREAD; ++i) {
        pthread_join(thread[i], NULL);
    }
    return 0;
}

void *sub_routine(void *arg) {
    int local;
    size_t i;
    for (i = 0; i < 100000000 / MAX_THREAD; i++) {
        /** 오차가 적어지는 개선은 되지만, 아직도 오차가 발생한다. */
        /** 대기하는 while 문과 값을 변경하는 코드가 두 단계로 나뉘어져서 동작을 하기 때문이다. */
        while (g_mutex);
        g_mutex = 1;
        ++g_sum;
        g_mutex = 0;
    }
    return arg;
}

