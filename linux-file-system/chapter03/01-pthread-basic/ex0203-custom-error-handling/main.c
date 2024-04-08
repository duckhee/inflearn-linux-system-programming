#include "customerrors.h"
#include <pthread.h>
#include <unistd.h>


void *thread_subroutine(void *);

int main(void) {
    printf("hello\r\n");
    /** thread 의 정보를 저장하기 위한 변수 */
    pthread_t thread_id;
    /** 종료 코드를 저장하기 위한 변수 */
    void *thread_result = NULL;
    /** 에러 코드를 저장하기 위한 변수 */
    int status;
    status = pthread_create(&thread_id, NULL, thread_subroutine, 0);
    DPRINTF("%s hello\n", "test");
    if (status != 0) {
        /** error 발생 시 어디서 에러가 발생 했는지 알려주는 출력 */
        err_abort(status, "Create Thread");
    }
    /** thread 를 종료 처리하는 함수 -> 호출된 Thread 가 인자로 받은 상태 값을 반환 하는 형태로 종료가 된다.*/
//    pthread_exit(0);
    status = pthread_join(thread_id, &thread_result);
    if (status != 0) {
        /** error 발생 시 어디서 에러가 발생 했는지 알려주는 출력 */
        err_abort(status, "Join Thread");
    }
    if (thread_result != NULL) {
        /** 종료 코드를 출력 하는 함수 */
        printf("value : %d\r\n", *(int *) &thread_result);
        DPRINTF("Child Thread exit\r\n");
    } else {
        DPRINTF("Child Thread exit\r\n");
    }
    return 0;
}

void *thread_subroutine(void *arg) {
    sleep(1);
    return (void *) 1;
}
