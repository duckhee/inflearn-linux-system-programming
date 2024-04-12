#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

/** thread 가 동작할 함수 */
void *sub_routine(void *data);

/** 잠금 여부를 확인하기 위한 변수 */
int mutex = 1;

int main(void) {
    /** thread 에 대한 값을 저장하기 위한 변수 */
    pthread_t thread;
    /** thread 생성 */
    pthread_create(&thread, NULL, sub_routine, NULL);
    /** 대기를 위한 입력 */
    getchar();
    /** futex unlock -> interrupt 를 직접 번호로 호출해서 걸어주는 부분이라 칩에 따라 다르게 동작한다. */
    syscall(202, &mutex, 1, 1);
    /** thread 종료가 될 때 까지 대기하는 함수 */
    pthread_join(thread, NULL);
    return 0;
}

void *sub_routine(void *data) {
    /** futex lock -> interrupt 를 직접 번호로 호출해서 걸어주는 부분이라 칩에 따라 다르게 동작한다. */
    syscall(202, &mutex, 0, 1, 0);
    printf("after\r\n");
    return 0;
}
