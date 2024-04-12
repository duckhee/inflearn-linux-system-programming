#include <stdio.h>


typedef int int32_t;

/** assembler code 로 lock 구현 */
int __bionic_cmpxchg(int32_t old_value, int32_t new_value, volatile int32_t *ptr) {
    int32_t prev;
    __asm__ __volatile__ ("lock; cmpxchgl %1, %2"
            : "=a" (prev)
            : "q" (new_value), "m" (*ptr), "0" (old_value)
            : "memory"
            );
    return prev != old_value;
}

int mutex = 0;

/** 고속 회전을 돌면서 락을 건다고 해서 spin lock 이라고 한다. */
void spin_lock(int *lock) {
    while (__bionic_cmpxchg(0, 1, lock));
}

void spin_unlock(int *lock) {
    *lock = 0;
}

int main(void) {
//    int ret;
//    ret = __bionic_cmpxchg(0, 1, &mutex);
//    printf("mutex value : %d, ret value : %d\r\n", mutex, ret);
    spin_lock(&mutex);
    printf("testing\r\n");
    spin_unlock(&mutex);
    spin_lock(&mutex);
    printf("Mutex\r\n");
    spin_unlock(&mutex);
    return 0;
}
