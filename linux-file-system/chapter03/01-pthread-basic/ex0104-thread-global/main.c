#include <stdio.h>
#include <pthread.h>

/** Thread 는 전역 변수를 공유 한다. */
/** global variable */
int g_value = 6;

/** pthread flow function */
void *threadRoutine(void *);

int main(void) {
    int localValue = 10;
    /** Thread 에 대한 정보를 담기 위한 구조체 선언 */
    pthread_t thread;
    /** Thread 를 생성하는 함수 */
    pthread_create(&thread, NULL, threadRoutine, NULL);
    /** Thread 가 종료가 될 때까지 대기하는 함수 */
    pthread_join(thread, 0);
    /** global 변수에 대한 값을 확인하기 위한 출력 */
    printf("parent thread global value : %d\r\n", g_value);
    printf("local value : %d\r\n", localValue);
    return 0;
}

/** Thread 에서 동작할 함수에 대한 선언 */
void *threadRoutine(void *data) {
    /** */
    printf("child thread global value : %d\r\n", ++g_value);
    if (data != NULL) {
        printf("child thread local value : %d\r\n", ++*(int *) data);
    }
    return 0;
}
