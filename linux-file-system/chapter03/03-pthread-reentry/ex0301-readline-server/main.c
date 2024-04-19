#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_BUFFER_SIZE             1024

static pthread_key_t rl_key;
static pthread_once_t rl_once = PTHREAD_ONCE_INIT;


/** */
typedef struct _read {
    int read_cnt; // 읽어온 갯수를 저장하기 위한 변수
    char *read_ptr; //
    char read_buffer[MAX_BUFFER_SIZE];
} RLine_t;

static void readline_once_destructor(void *ptr) {
    free(ptr);
}

static void readline_once_init(void) {
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
    static int read_cnt = 0;
    static char *read_ptr;
    static char read_buf[MAX_BUFFER_SIZE];
    if (read_cnt <= 0) {
        if ((read_cnt = read(fd, read_buf, sizeof(read_buf))) < 0) {
            return (-1);
        } else if (read_cnt == 0) {
            return (0);
        }
        read_ptr = read_buf;
    }
    read_cnt--;
    *ptr = *read_ptr++;
    return (1);
}

/** Thread 의 safe 하도록 재 진입이 가능한 형태 */
/** 1 바이트 단위로 값을 읽어오기 위한 함수 */
ssize_t my_read(int fd, char *ptr, RLine_t *buf) {
    /** 처음 읽어온 것인지 읽어온 것에 대해서 실패를 했는지 여부를 확인하기 위한 조건문 */
    if (buf->read_cnt <= 0) {
        /** 1*/
        if ((buf->read_cnt = read(fd, buf->read_buffer, sizeof(buf->read_buffer))) < 0) {
            return (-1);
        } else if (buf->read_cnt == 0) {
            return (0);
        }
        buf->read_ptr = buf->read_buffer;
    }
    buf->read_cnt--;
    *ptr = *buf->read_ptr++;
    return (1);
}

ssize_t threadReadLine(int fd, void *vptr, size_t maxLen) {
    size_t i;
    int rc;
    char c, *ptr;
    RLine_t *tsd;
    pthread_once(&rl_once, readline_once_init);
    if ((tsd = pthread_getspecific(rl_key)) == NULL) {
        tsd = calloc(1, sizeof(RLine_t));
        pthread_setspecific(rl_key, tsd);
    }
    ptr = vptr;
    for (i = 1; i < maxLen; i++) {
        if ((rc = my_read(fd, &c, tsd)) == 1) {
            *ptr++ = c;
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
        rc = read(fd, &c, 1);
        /** 문자를 읽어와서 버퍼에 값 저장 */
        if (rc == 1) {
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
