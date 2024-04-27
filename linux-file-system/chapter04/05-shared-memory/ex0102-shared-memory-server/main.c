#include <stdio.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>

/** 공유 메모리에 저장하기 위한 구조체 */
typedef struct _SharedMemory {
    int count;
    char name[256];
} SHM_t;

/** 공유 메모리를 생성하기 위한 함수 */
int createSharedMemory(long key) {
    /** 공유 메모리를 생성하는 함수 */
    return (shmget(key, sizeof(SHM_t), IPC_CREAT | 0777));
}

/** 공유 메모리에 접근하기 위한 함수 */
int openSharedMemory(long key) {
    /** 공유 메모리에서 구조체만큼 가져오기 */
    return (shmget(key, sizeof(SHM_t), 0));
}

/** 공유 메모리에 연결 시켜주는 함수 */
SHM_t *getSharedMemoryPointer(int shmid) {
    /** shared memory attached */
    /** 공유 메모리에 연결해서 값을 가져오는 함수 -> 주소 값을 NULL 값을 넣어주면, kernel 이 알아서 매핑을 시켜준다. option 을 0을 넣어주면 읽기와 쓰기가 가능하다. */
    return (SHM_t *) shmat(shmid, (char *) 0, 0);
}

/** 공유 메모리를 해제하기 위한 함수이다. */
int freeSharedMemory(SHM_t *shmptr) {
    /** shared memory detached */
    /** 공유 메모리에 대한 연결을 해제하는 함수이다. */
    return shmdt((char *) shmptr);
}

/** 공유 메모리를 삭제하는 함수이다.  */
int removeSharedMemory(int shmid) {
    /** 공유 메모리를 삭제하는 함수 */
    return shmctl(shmid, IPC_RMID, (struct shmid_ds *) 0);
}

int main(void) {
    /** 공유 메모리의 식별자를 저장하기 위한 변수 */
    int shared_memory_id;
    /** 공유 메모리의 주소 값을 담기 위한 변수 */
    SHM_t *pSharedMemory = NULL;
    /** 공유 메모리를 생성해서 식별자 저장하기 */
    shared_memory_id = createSharedMemory(5000);
    /** 공유 메모리에서 데이터를 가져오기 */
    pSharedMemory = getSharedMemoryPointer(shared_memory_id);
    /** 대기하기 위한 함수 */
    getchar();
    /** 공유 메모리에서 값을 가져와서 출력 */
    printf("[%d] %d, %s\r\n", shared_memory_id, pSharedMemory->count, pSharedMemory->name);
    /** 공유 메모리를 삭제 */
    removeSharedMemory(shared_memory_id);

    return 0;
}

