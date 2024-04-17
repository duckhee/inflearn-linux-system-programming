#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

void *phone_strtok(void *);
void *ip_strtok(void *);

int main(void){
    /** thread 에 대한 자료 구조를 담기 위한 변수 배열 */
    pthread_t str[2];
    /** thread 생성*/
    pthread_create(&str[0], NULL, phone_strtok, NULL);
    pthread_create(&str[1], NULL, ip_strtok, NULL);
    /** thread 완료될 때 까까지 대기 */
    pthread_join(str[0], NULL);
    pthread_join(str[1], NULL);
    return 0;
}

void *phone_strtok(void *data){
    char hp[] = "010-1234-5678";
    char *p;
    /** 잘라진 값을 넣기 위한 포인터 변수 */
    char *savePointer;
    /** 재 진입이 가능한 strtok 함수 */
    p = strtok_r(hp, "-", &savePointer);
    while(p){
        printf("[%s]\r\n", p);
        sleep(1);
        /** 계속해서 문자열을 이어서 자르기 위한 사용 */
        p = strtok_r(NULL, "-", &savePointer);
    }
}

void *ip_strtok(void *data){
    char ip[] = "127.0.0.1";
    char *p;
    /** 잘라진 값을 넣기 위한 포인터 변수 */
    char *savePointer;
    /** 재 진입이 가능한 strtok 함수 */
    p = strtok_r(ip, ".", &savePointer);
    while(p){
        printf("[%s]\r\n", p);
        sleep(1);
        /** 계속해서 문자열을 이어서 자르기 위한 사용 */
        p = strtok_r(NULL, ".", &savePointer);
    }
}
