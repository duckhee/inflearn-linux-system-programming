#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include <errno.h>

typedef struct msg_q {
    long to_mtype;
    long fm_mtype;
    char mtext[100];
} MSG_t;

int createMessageQueue(long key) {
    /** message queue 를 생성하는 함수 -> msgget(key_t key, int msgflag); */
    /** 0777 을 넣어주는 것은 누구나 사용할 수 있도록 해주기 위한 권한에 대한 값을 넣어준다. */
    return (msgget(key, IPC_CREAT | 0777));
}

int openMessageQueue(long key) {
    /** message queue 에 대한 식별자를 가져오기 위해서는 flag 를 0으로 넣어주면 된다. */
    /** Message Queue 에 대해서 열기 위해서 사용이 되다.  */
    return (msgget(key, 0));
}

long sendMessageQueue(int qid, long mType, MSG_t msg) {
    /** 전ㄷ라 성공 여부를 저장하기 위한 변수 */
    int st;
    /** message 의 타읩에 대한 설정 */
    msg.to_mtype = mType;
    /** 메세지를 전송하는 프로세스에 대한 정보를 넣어준다. */
    msg.fm_mtype = getpid();
    /** msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflag) msqid 를 식별자로 가지는 메세지 큐에 msgp 에 있는 메시지를 전달하는 함수이다. */
    /** msg send 성공 시에는 0 반환 실패 시 -1 반환 */
    /** 비동기적으로 사용 */
    st = msgsnd(qid, &msg, (sizeof(MSG_t) - sizeof(long)), IPC_NOWAIT);
    if (st < 0) {
        return -1l;
    }
    return msg.fm_mtype;
}

long receiveMessageQueue(int qid, long mType, MSG_t *msg) {
    int st;
    /** Message Queue 에서 값을 가져오는 함수 */
    st = msgrcv(qid, msg, sizeof(MSG_t) - sizeof(long), mType, IPC_NOWAIT);
    if (st < 0) {
        return -1l;
    }
    return msg->fm_mtype;
}

int getFreeSizeOfMessageQueue(int qid, long *pFreeSize) {
    int rtn;
    /**  Message Queue 에 대한 정보를 저장하기 위한 변수 */
    struct msqid_ds stat_q;

    if (qid < 0) {
        return -1;
    }
    /** messag queue 에 대한 제어하는 함수 */
    rtn = msgctl(qid, IPC_STAT, &stat_q);
    if (rtn < 0) {
        return -1;
    }
    /** 사용 가능한 메모리 공간에 대한 값을 구하는 계산 */
    *pFreeSize = stat_q.msg_qbytes - stat_q.msg_cbytes;
    return rtn;
}

int removeMessageQueue(int qid) {
    /** message queue 를 삭제 하는 함수 */
    return (msgctl(qid, IPC_RMID, 0));
}

int main(void) {
    return 0;
}
