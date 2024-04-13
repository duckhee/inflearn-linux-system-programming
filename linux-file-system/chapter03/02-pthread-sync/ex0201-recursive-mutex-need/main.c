#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;

int g_sum = 0;

int recursive_loop(int i) {
    if (i == 0) {
        return i;
    }
    pthread_mutex_lock(&mutex);
    printf("임계 영역 - critical section\r\n");
    g_sum = i * recursive_loop(i - 1);
    pthread_mutex_unlock(&mutex);
    return g_sum;
}

int main(void) {
    pthread_mutex_init(&mutex, NULL);
    recursive_loop(5);
    printf("sum value : %d\r\n", g_sum);
    pthread_mutex_destroy(&mutex);
    return 0;
}
