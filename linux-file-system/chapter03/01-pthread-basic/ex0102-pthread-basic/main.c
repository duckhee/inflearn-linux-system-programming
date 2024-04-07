#include <stdio.h>
#include <pthread.h>


/** */
void *start_routine(void *);

int main(void) {
    /** pthread 에서 thread 를 생성하기 위한 객체 -> process 를 생성하고 받는 pid 와 동일한 역활을 한다. */
    pthread_t thread;
    /** pthread 를 이용해서 thread 를 생성하는 함수 */
    pthread_create(&thread, 0, start_routine, 0);
    /** thread 를 수거하기 위해서 대기하는 함수이다. */
    pthread_join(thread, 0);
    printf("parent thread\r\n");
    return 0;
}

void *start_routine(void *data) {
    printf("\t\tchild thread\r\n");
    return 0;
}
