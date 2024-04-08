#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>


int main(void) {
    int ret;
    /** 없는 thread 생성 */
    pthread_t thread = (pthread_t) 0x7777;
    /** 없는 thread 를 기다리는 함수 */
    ret = pthread_join(thread, 0);
    if (ret != 0) {
        printf("[%s] ret = %d\r\n", strerror(ret), ret);
    }
    printf("ret = %d\r\n", ret);
    return 0;
}
