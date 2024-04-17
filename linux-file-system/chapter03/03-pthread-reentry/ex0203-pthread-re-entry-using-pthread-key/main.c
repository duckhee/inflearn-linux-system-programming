#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

/** thread local storage 를 사용하기 위한 변수 */
pthread_key_t pthreadKey;

/** */
void countCalLByFunc(void);

/** */
void *handler1(void *);
/** */
void *handler2(void *);
/** */
void destructor_key(void *);

int main(void) {
    /** thread 에 대한 정보를 담기 위한 thread 구초제를 담공 있는 배열 */
    pthread_t thread[2];
    /** Thread Local Storage 을 사용할 때 사용할 키 값과 Thread Local Storage 이 제거가 될 때 호출될 함수를 등록 하면서 Thread Local Storage 를 생성하는 함수 */
    pthread_key_create(&pthreadKey, destructor_key);
    /** thread 를 생성해주는 함수*/
    pthread_create(&thread[0], NULL, handler1, NULL);
    pthread_create(&thread[1], NULL, handler2, NULL);
    /** thread 가 종료가 될 때까지 대기하는 함수 */
    pthread_join(thread[0], NULL);
    pthread_join(thread[1], NULL);
    return 0;
}

void countCalLByFunc(void) {
    int *tsd;
    /** Thread Local Storage 에서 해당 키 값으로 저장된 값을 가져오는 함수 */
    tsd = pthread_getspecific(pthreadKey);
    /** Thread Local Storage 에 값이 없을 경우 */
    if (tsd == 0) {
        /** Thread Local Storage 에서 사용할 값에 대한 0으로 초기화된 상태로 동적 메모리 할당 */
        tsd = calloc(1, sizeof(int));
        printf("tsd address : [%p]\r\n", (void *)tsd);
        /** Thread Local Storage 에 해당 키 값의 해당 값을 저장 하는 함수 */
        pthread_setspecific(pthreadKey, tsd);
    }
    printf("count = %d\r\n", ++*tsd);
}

/** thread 에서 동작할 sub routine */
void *handler1(void *data) {
    countCalLByFunc();
    countCalLByFunc();
    countCalLByFunc();
}

/** thread 에서 동작할 sub routine */
void *handler2(void *data) {
    countCalLByFunc();
    countCalLByFunc();
    countCalLByFunc();
}

/** Thread Local Storage 가 제거될 떄 불릴 함수이다. -> 동적으로 할당한 값들에 대해서 메모리 해제 등 특정 작업을 하기 위해서 사용이 된다. */
void destructor_key(void *pVoid) {
    printf("destructor_key key address : [%p]\r\n", pVoid);
    /** Thread Local Storage 에서 사용한 값을 메모리에서 해제 시켜준다. -> tsd 값을 메모리에서 제거 */
    free(pVoid);
}
