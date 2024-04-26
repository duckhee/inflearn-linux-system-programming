#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>
#include <errno.h>

#define SEMPREM         0666

int createSemaphore(key_t semkey) {
    /** 상태 값을 저장하기 위한 변수 */
    int status = 0;
    /** semaphore 의 식별자를 저장하기 위한 변수 */
    int semid;
    /** semaphore 가 존재하면 연결 존재하지 않으면 생성하는 함수 및 오류 발생 시 조건문 */
    if ((semid = semget(semkey, 1, 0666 | IPC_CREAT | IPC_EXCL)) == -1) {
        /** semaphore 가 이미 존재할 경우 */
        if (errno == EEXIST) {
            /** semaphore 에 접근하기 위한 열기 */
            semid = semget(semkey, 1, 0);
        }
    }
        /** 성공적으로 semaphore 에 접속이 되었을 경우 */
    else {
        /** semaphore 의 값을 설정하는 것 */
        status = semctl(semid, 0, SETVAL, 1);
    }
    /** semaphore 열기 및 생성 setting 실패 시 */
    if (semid == -1 || status == -1) {
        return -1;
    }
    return semid;
}

int p(int semid) {
    /** semaphore 에 대한 정보를 담기 위한 구조체 */
    struct sembuf p_buf;
    p_buf.sem_num = 0;
    /** semaphore 에 lock 을 획득이 된다. */
    p_buf.sem_op = -1;
    /** 비정상적으로 종료가 되면 semaphore 에 대한 locking 에 되어 있는 것을 해제 시키기 위한 flag -> 역순 연산을 하도록 한다. */
    p_buf.sem_flg = SEM_UNDO;
    /** semaphore 연산 진행 및 접근할 수 있는 process 갯수 1개로 설정 */
    if (semop(semid, &p_buf, 1) == -1) {
        return -1;
    }
    return 0;
}

int v(int semid) {
    /** semaphore 에 대한 정보를 담기 위한 구조체 */
    struct sembuf v_buf;
    v_buf.sem_num = 0;
    /** semaphore 에 lock 을 반환한다. */
    v_buf.sem_op = 1;
    /** 비정상적으로 종료가 되면 semaphore 에 대한 locking 에 되어 있는 것을 해제 시키기 위한 flag -> 역순 연산을 하도록 한다. */
    v_buf.sem_flg = SEM_UNDO;
    /** semaphore 연산 진행 및 접근할 수 있는 process 갯수 1개로 설정 */
    if (semop(semid, &v_buf, 1) == -1) {
        return -1;
    }
    return 0;
}

int removeSemaphore(int semid) {
    /** semaphore 를 삭제하기 위한 함수 및 실패 시 조건 문 */
    if (semctl(semid, IPC_RMID, 0) == -1) {
        printf("failed remove semaphore : %d\r\n", semid);
        return -1;
    }
    printf("remove semaphore\r\n");
    return 0;
}

int main(void) {
    /** semaphore id 저장하기 위한 변수 */
    int semid;
    /** semaphore 생성 */
    semid = createSemaphore(5000);
    printf("create semaphore : %d\r\n", semid);
    /** 임계 영역 전입 */
    p(semid);
    printf("임계영역 진입 \r\n");
    getchar();
    /** 임계 영역 탈출 */
    v(semid);
    printf("임계영역 탈출\r\n");
    removeSemaphore(semid);
    return 0;
}
