#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex;
pthread_mutexattr_t mutex_attr;

int main(void) {
    pthread_mutexattr_init(&mutex_attr);
    pthread_mutexattr_settype(&mutex_attr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&mutex, &mutex_attr);
    pthread_mutex_lock(&mutex);
    pthread_mutex_lock(&mutex);
    printf("임계 영역 진입\r\n");
    pthread_mutex_unlock(&mutex);
    pthread_mutex_unlock(&mutex);
    pthread_mutex_destroy(&mutex);
    return 0;
}
