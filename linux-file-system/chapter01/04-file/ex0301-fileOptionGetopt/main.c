#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define LIST        (1<<0) // 0x0001 -> 1
#define INODE       (1<<1) // 0x0010 -> 2
#define RECUR       (1<<2) // 0x0100 -> 4
#define ALL         (1<<3) // 0x1000 -> 8


int main(int argc, char **argv) {
    /** option 의 값을 저장하기 위한 변수 */
    int ch;
    int flag = 0;
    /** 들어온 argument 를 확인하기 위한 반복문 */
//    for (size_t i = 0; i < argc; ++i) {
//        printf("%s ", argv[i]);
//    }
    /** 어떤 option 이 들어왔는지 확인하기 위한 반복문 -> liRa 만 parsing 하는 함수가 getopt 함수이다. */
    while ((ch = getopt(argc, argv, "liRa")) != -1) {
        switch (ch) {
            case 'l':
                flag |= LIST;
                break;
            case 'i':
                flag |= INODE;
                break;
            case 'R':
                flag |= RECUR;
                break;
            case 'a':
                flag |= ALL;
                break;
        }
    }
    /** option 에 대한 출력을 위한 bit 연산 -> 배열에 넣는 방식은 너무 많은 메모리를 사용하므로 메로리 사용을 줄이기 위해 bit mask 를 이용한다. */
    if (flag & LIST) {
        printf("l\r\n");
    }
    if (flag & INODE) {
        printf("i\r\n");
    }
    if (flag & RECUR) {
        printf("R\r\n");
    }
    if (flag & ALL) {
        printf("a\r\n");
    }
    return 0;
}
