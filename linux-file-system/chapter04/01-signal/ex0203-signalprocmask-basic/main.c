#include <signal.h>
#include <unistd.h>


int main(void) {
    /** sigset_t 은 추상 데이터 타입은 대입을 통해 초기화가 불가능하므로 초기화 하는 함수가 내부적으로 정의가 되어 있다. */
    sigset_t set;
    sigset_t oldSet;
    /** sigset_t 초기화 하는 함수 */
    sigemptyset(&set);
    sigemptyset(&oldSet);

    /** 2번 시그널에 대한 설정 */
    sigaddset(&set, SIGINT);
    /** 덮어 쓰는 형식으로 설정 */
    sigprocmask(SIG_BLOCK, &set, &oldSet);
    /** 대기하는 동안에 signal 에 대한 처리를 보류 하는 임계 영역이 된다. */
    sleep(3);
    /** 원래 신호 형태로 변경하는 것 */
    sigprocmask(SIG_SETMASK, &oldSet, 0);
    return 0;
}
