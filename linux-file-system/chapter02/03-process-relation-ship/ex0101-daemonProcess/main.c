#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>
#include <syslog.h>

int daemon_init(void);

int main(void) {
    /** daemon 프로세스를 만들기 위한 방법 */
    daemon_init();
    /** daemon 일 경우 키보드와 모니터 연결이 끊어져 있기 때문에 printf 와 같은 입출력 함수가 동작하지 않으므로 해당 함수를 사용해서 남겨야한다. */
    /** 해당 로그가 생성되는 파일의 위치는 /var/log/syslog 에 저장이 된다.*/
    syslog(1, "%s\r\n", "daemon");

    return 0;
}

/** daemon process 생성 하는 함수 */
int daemon_init(void) {
    /** process pid 를 저장하기 위한 변수 */
    pid_t pid;
    /** process 생성 */
    pid = fork();
    /** 부모 프로세스 종료 */
    if (pid > 0) {
        exit(0);
    }
    /** 새로운 프로세스 세션 생성 */
    setsid();
    /** 최상위 디렉토리의 위치로 작업 위치 변경 */
    chdir("/");
    /** 부모 프로세스로 부터 상속 받은 사용자 마스크 정보 초기화 */
    umask(0);
    /** 부모로 부터 상속 받은 파일 디스크립터 닫아주기 */
    for (size_t i = 0; i < 64; ++i) {
        close(i);
    }
    /** 자식 프로세스가 발생 시키는 시그널인 SIGCHLD에 대해서 처리하기 위한 signal 함수 사용 */
    signal(SIGCHLD, SIG_IGN);
    return (0);
}
