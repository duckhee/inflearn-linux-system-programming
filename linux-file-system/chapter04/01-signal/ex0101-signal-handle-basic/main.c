#include <signal.h>

int main(void) {
    /** signal SIGINT(signal interrupt)가 발생 시 무시하도록 설정 */
    signal(SIGINT, SIG_IGN);
    /** 종료 신호에 대한 발생 시 무시하도록 설정  */
    signal(SIGQUIT, SIG_IGN);
    /** 프로그램을 죽이는 신호를 무시하도록 설정 -> 해당 신호와 멈춤 신호는 시그널에 대한 처리가 불가능하다. (정해진 되도만 사용이 된다) */
    signal(SIGKILL, SIG_IGN);
    while (1);
    return 0;
}
