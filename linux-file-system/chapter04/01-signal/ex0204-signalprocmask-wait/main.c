#include <stdio.h>
#include <signal.h>

/** signal mask 의 정보를 보기 위한 함수 */
void show_mask(void);


int main(void) {

    sigset_t set;
    sigset_t oldSet;
    /** signal 에 대한 구조체를 초기화 해주는 코드 */
    sigemptyset(&set);
    sigemptyset(&oldSet);
    /** SIGQUIT 함수에 대한 마스킹 작업 */
    sigaddset(&set, SIGQUIT);

    /** 현재 signal 에 대한 값을 새로운 값으로 덮어 쓰는 함수 실행 후 에러 발생 시 출력할 조건문 */
    if (sigprocmask(SIG_BLOCK, &set, &oldSet) < 0) {
        printf("sigprocmask error\r\n");
    }
    /** signal mask 의 정보를 보기 위한 함수 */
    show_mask();
    /** */
    if (sigprocmask(SIG_SETMASK, &oldSet, NULL) < 0) {
        printf("sigprocmask error\r\n");
    }
    return 0;
}

/** signal mask 의 정보를 보기 위한 함수 */
void show_mask(void) {
    sigset_t showSet;
    /** 동작 모드에 대해서 값을 넣는 인자를 0으로 넣어서 백업되는 데이터를 가져오는 것이다. */
    if (sigprocmask(0, NULL, &showSet) < 0) {
        printf("sigprocmask error");
    }
    /** Interrupt 발생 시 생성되는 signal 인지 확인 */
    if (sigismember(&showSet, SIGINT)) {
        printf("SIGINT");
    }
    /** QUIT 발생 시 생성되는 signal 인지 확인 */
    if (sigismember(&showSet, SIGQUIT)) {
        printf("SIGQUIT");
    }
    /** SIGUSR1 발생 시 생성되는 signal 인지 확인 */
    if (sigismember(&showSet, SIGUSR1)) {
        printf("SIGUSR1");
    }
    /** SIGALRM 발생 시 생성되는 signal 인지 확인 */
    if (sigismember(&showSet, SIGALRM)) {
        printf("SIGALRM");
    }
    printf("\r\n");
}
