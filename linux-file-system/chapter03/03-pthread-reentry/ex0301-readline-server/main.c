#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_BUFFER_SIZE             4096 //((1024)*(4)) = 4096 4K

/** Local Thread Storage에서 접근을 할 때 사용될 구조체 */
static pthread_key_t rl_key;
/** thread에서 전역적으로 사용할 변수의 생성 및 초기화 */
static pthread_once_t rl_once = PTHREAD_ONCE_INIT;


/** */
typedef struct _read {
    int read_cnt; // 읽어온 갯수를 저장하기 위한 변수
    char *read_ptr; // 값을 포인터로 접근하기 위한 포인터 변수
    char read_buffer[MAX_BUFFER_SIZE]; // 읽어온 값을 저장하기 위한 버퍼
} RLine_t;

/** Local Thread Storage 에서 Thread 가 종료될 때 호출될 소멸자 */
static void readline_once_destructor(void *ptr) {
    /** Local Thread Storage 에 동적 할당된 메모리를 제거해주는 코드 */
    free(ptr);
}

/** 전역적으로 관리를 해줄 함수 */
static void readline_once_init(void) {
    /** Local Thread Storage 에 한번만 등록이 되어야 한다. */
    pthread_key_create(&rl_key, readline_once_destructor);
}

/** 1 바이트 단위로 값을 읽어오기 위한 함수 */
ssize_t oldMyRead(int fd, char *ptr);

ssize_t my_read(int fd, char *ptr, RLine_t *buffer);

/** 엔터 값을 입력을 받아서 읽어서 처리하기 위한 함수 */
ssize_t threadReadLine(int fd, void *vptr, size_t maxLen);

ssize_t readline(int fd, void *vptr, size_t maxLen);

ssize_t oldReadline(int fd, void *vptr, size_t maxLen);

int main(void) {
    int fd;
    char readBuffer[MAX_BUFFER_SIZE];
    int readResult;
    fd = open("myfifo", O_RDWR);
    if (fd <= 0) {
        printf("file descriptor failed ... \r\n");
        return -1;
    }
//    while ((readResult = read(fd, readBuffer, sizeof readBuffer))) {
//    while ((readResult = readline(fd, readBuffer, sizeof readBuffer))) {
    while ((readResult = threadReadLine(fd, readBuffer, sizeof readBuffer))) {
        /** 읽어온 buffer 만큼 화면에 출력 -> 1번은 모니터의 file descriptor 이다. */
        write(1, readBuffer, readResult);

    }
    printf("program run end %d\r\n", readResult);
    return 0;
}

ssize_t oldMyRead(int fd, char *ptr) {
    /** 읽어올 값에 대한 숫자를 저장하기 위한 전역 변수 */
    static int read_cnt = 0;
    /** 읽어온 값을 전역적으로 관리하기 위한 포인터 */
    static char *read_ptr;
    /** 값을 젖장하기 위한 버퍼 */
    static char read_buf[MAX_BUFFER_SIZE];
    /** 처음 동작할 때 확인 */
    if (read_cnt <= 0) {
        /** 읽어올 수 없을 경우 */
        if ((read_cnt = read(fd, read_buf, sizeof(read_buf))) < 0) {
            return (-1);
        }
            /** 다 읽어 왔을 경우 */
        else if (read_cnt == 0) {
            return (0);
        }
        /** 값에 대한 포인터 접근을 위한 변수에 복사 */
        read_ptr = read_buf;
    }
    /** 값을 읽어오면서 counter 감소 */
    read_cnt--;
    /** 값을 하나씩 읽어와서 값을 인자에 넣어서 전달 */
    *ptr = *read_ptr++;
    return (1);
}

/** Thread 의 safe 하도록 재 진입이 가능한 형태 */
/** 1 바이트 단위로 값을 읽어오기 위한 함수 */
ssize_t my_read(int fd, char *ptr, RLine_t *buf) {
    /** 처음 읽어온 것인지 읽어온 것에 대해서 실패를 했는지 여부를 확인하기 위한 조건문 */
    /** 처음 읽어왔을 때 kernel의 4kb를 읽어오고 다음 두번째 읽어왔을 때는 남아 있는 counter 가 있기 때문에 실행이 되지 않는다. */
    if (buf->read_cnt <= 0) {
        /** 읽어온 값이 잘못되었을 경우 출력 */
        if ((buf->read_cnt = read(fd, buf->read_buffer, sizeof(buf->read_buffer))) < 0) {
            return (-1);
        }
            /** 모든 문자를 읽어왔을 때 처리 하는 함수 */
        else if (buf->read_cnt == 0) {
            return (0);
        }
        buf->read_ptr = buf->read_buffer;
    }
    /** 읽을 갯수에 대한 카운터 변수를 감소 */
    buf->read_cnt--;
    /** 인자에 해당 문자 값을 반환 */
    *ptr = *buf->read_ptr++;
    return (1);
}

ssize_t threadReadLine(int fd, void *vptr, size_t maxLen) {
    size_t i;
    int rc;
    char c, *ptr;
    /** thread local storage */
    RLine_t *tsd;
    /** process 내에 전역적으로 사용할 thread local storage 에 전역 변수로 선언 및 초기화 */
    pthread_once(&rl_once, readline_once_init);
    /** thread local storage 에서 해당 key 값으로 값 가져올 것이 없을 경우 */
    if ((tsd = pthread_getspecific(rl_key)) == NULL) {
        /** 해당 구조체를 저장할 만큼 동적 할당 */
        tsd = calloc(1, sizeof(RLine_t));
        /** thread local storage 에 해당 값을 등록 */
        pthread_setspecific(rl_key, tsd);
    }
    /** 얕은 복사 */
    ptr = vptr;
    /** 최대 범위까지 반복 진행 */
    for (i = 1; i < maxLen; i++) {
        /** */
        if ((rc = my_read(fd, &c, tsd)) == 1) {
            /** 읽어온 값을 저장 */
            *ptr++ = c;
            /** \n 의 값이 들어올 경우 for 문 종료 */
            if (c == '\n') {
                break;
            }
        }
            /** 읽어온 값이 없을 경우 */
        else if (rc == 0) {
            /** EOF, no data read */
            if (i == 1) {
                return 0;
            }
                /** EOF, some data was read */
            else {
                break;
            }
        }
            /** error, errno set by read() */
        else {
            return (-1);
        }
    }
    /** null terminate like fgets() */
    *ptr = 0;
    return (i);
}


/** 엔터 값을 입력을 받아서 읽어서 처리하기 위한 함수 */
ssize_t readline(int fd, void *vptr, size_t maxLen) {
    size_t i;
    int rc;
    char c, *ptr;

    RLine_t buffer = {0,};
    ptr = vptr;
    for (i = 1; i < maxLen; ++i) {
//        rc = my_read(fd, &c, &buffer);
        /** 문자를 읽어와서 버퍼에 값 저장 */
        /** */
//        if((rc = oldMyRead(fd, &c)) == 1){
        if ((rc = my_read(fd, &c, &buffer)) == 1) {
            *ptr++ = c;
            /* newline is stored, like fgets() */
            if (c == '\n') {
                break;
            }
        }
            /** 읽어온 값이 없을 경우 */
        else if (rc == 0) {
            /** EOF, no data read */
            if (i == 1) {
                return 0;
            }
                /** EOF, some data was read */
            else {
                break;
            }
        }
            /** error, errno set by read() */
        else {
            return (-1);
        }
    }
    /** null terminate like fgets() */
    *ptr = 0;
    return (i);
}


/** 엔터 값을 입력을 받아서 읽어서 처리하기 위한 함수 */
ssize_t oldReadline(int fd, void *vptr, size_t maxLen) {
    size_t i;
    int rc;
    char c, *ptr;
    ptr = vptr;
    for (i = 1; i < maxLen; ++i) {

        /** 문자를 읽어와서 버퍼에 값 저장 */
        if ((rc = read(fd, &c, 1)) == 1) {
            /** 문자열의 배열 포인터의 위치를 증가 시키고, 해당 값을 저장 */
            *ptr++ = c;
            /** newline is stored, like fgets() */
            if (c == '\n') {
                break;
            }
        }
            /** 읽어온 값이 없을 경우 */
        else if (rc == 0) {
            /** EOF, no data read */
            if (i == 1) {
                return 0;
            }
                /** EOF, some data was read */
            else {
                break;
            }
        }
            /** error, errno set by read() */
        else {
            return (-1);
        }
    }
    /** null terminate like fgets() */
    *ptr = 0;
    return (i);
}
