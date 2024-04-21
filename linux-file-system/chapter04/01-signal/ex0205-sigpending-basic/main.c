#include <stdio.h>
#include <signal.h>
#include <unistd.h>

/** 전역 함수 선언 */
static void sig_quit(int signo);

int main(void) {
    /** signal 에 대한 구조체를 담기 위한 변수 */
    sigset_t newMask, oldMask, pendingMask;
    /** SIGQUIT 신호가 들어왔들 떄 동작할 함수 등록 및 등록 에러 발생 시 실행할 조건문 */
    if (signal(SIGQUIT, sig_quit) == SIG_ERR) {
        /** 해당 신호를 처리할 수 없다고 출력 */
        printf("can't catch SIGQUIT\r\n");
    }
    /** signal 에 대한 구조체를 초기화 해주는 코드 */
    sigemptyset(&newMask);
    sigemptyset(&oldMask);
    sigemptyset(&pendingMask);
    /** SIGQUIT 함수에 대한 마스킹 작업 */
    sigaddset(&newMask, SIGQUIT);

    /** 현재 signal 에 대한 값을 새로운 값으로 덮어 쓰는 함수 실행 후 에러 발생 시 출력할 조건문 */
    if (sigprocmask(SIG_BLOCK, &newMask, &oldMask) < 0) {
        printf("SIG_BLOCK Error\r\n");
    }
    /** 대기하기 위한 함수 */
    sleep(5);
    /** 현재 발생된 signal 이 block 시켜서 가져온다. */
    if (sigpending(&pendingMask) < 0) {
        printf("pending mask error \r\n");
    }

    /** 해당 시그널에 대한 것이 SIGQUIT 인지 확인하는 조건문 */
    if (sigismember(&pendingMask, SIGQUIT)) {
        printf("SIGQUIT pending \r\n");
    }

    /** 원래 시그널에 대한 상태로 돌리는 작업 및 에러 발생 확인 조건문 */
    if (sigprocmask(SIG_SETMASK, &oldMask, NULL) < 0) {
        printf("SIG_SETMASK Error\r\n");
    }
    /** SIGQUIT 시그널을 막았던 것을 풀렸다고 알려주는 출력문 */
    printf("SIGQUIT Unblock\r\n");
    /** 종료 전에 대기하는 함수 */
    sleep(5);
    return 0;
}

/** static 함수로 signal 처리를 위한 함수 */
static void sig_quit(int signo) {
    /** 함수 진입에 대해서 알려주는 출력문 */
    printf("catch SIGQUIT %d\r\n", signo);
    /** SIGQUIT 신호에 대한 실행을 위한 함수 등록 */
    if (signal(SIGQUIT, SIG_DFL) == SIG_ERR) {
        printf("can't reset SIGQUIT\r\n");
    }
    return;
}
