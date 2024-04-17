#include <stdio.h>
#include <pthread.h>

void countCallFunc(const char *,int *);

void *thread_handler1(void *);
void *thread_handler2(void *);

int main(void){
    /** thread 에 대한 정보를 담고 있을 수 있는 Thread 구조체의 배열 변수 */
    pthread_t thread[2];
    /** Thread 생성 */
    pthread_create(&thread[0], NULL, thread_handler1, "thread1");
    pthread_create(&thread[1], NULL, thread_handler2, "thread2");
    /** Thread 종료될 때 까지 대기하는 함수 */
    pthread_join(thread[0], NULL);
    pthread_join(thread[1], NULL);
    return 0;
}

/** call by address 형태로 전역 변수인 static 변수를 제거하는 방식으로 재진입 진행 */
void countCallFunc(const char *str,int *pCount){
    printf("[%s] count = %d\r\n", str, ++*pCount);
}

void *thread_handler1(void *data){
    int count = 0;

    char *ptr = (char *)data;
    /** call by address 형태로 전역 변수인 static 변수를 제거하는 방식으로 재진입 진행 */
    countCallFunc(ptr,&count);
    countCallFunc(ptr,&count);
}

void *thread_handler2(void *data){
    int count = 0;
    char *ptr = (char *)data;
    /** call by address 형태로 전역 변수인 static 변수를 제거하는 방식으로 재진입 진행 */
    countCallFunc(ptr,&count);
    countCallFunc(ptr,&count);
    countCallFunc(ptr,&count);
}
