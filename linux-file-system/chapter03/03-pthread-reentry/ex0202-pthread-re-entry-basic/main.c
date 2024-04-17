#include <stdio.h>
#include <pthread.h>

void countCallFunc(const char *,int *);

void *thread_handler1(void *);
void *thread_handler2(void *);

int main(void){
    pthread_t thread[2];
    pthread_create(&thread[0], NULL, thread_handler1, "thread1");
    pthread_create(&thread[1], NULL, thread_handler2, "thread2");

    pthread_join(thread[0], NULL);
    pthread_join(thread[1], NULL);
    return 0;
}

void countCallFunc(const char *str,int *pCount){
    printf("[%s] count = %d\r\n", str, ++*pCount);
}

void *thread_handler1(void *data){
    int count = 0;
    char *ptr = (char *)data;

    countCallFunc(ptr,&count);
    countCallFunc(ptr,&count);
}

void *thread_handler2(void *data){
    int count = 0;
    char *ptr = (char *)data;

    countCallFunc(ptr,&count);
    countCallFunc(ptr,&count);
    countCallFunc(ptr,&count);
}
