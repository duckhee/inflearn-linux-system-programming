#include <stdio.h>
#include <unistd.h>


int main(int argc, char **argv) {
    fork();
    printf("after\r\n");
    return 0;
}
