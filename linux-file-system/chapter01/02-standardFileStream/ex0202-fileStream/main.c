#include <stdio.h>
#include <unistd.h>

#define BUFFER_MAX          1024

int main(int argc, char **argv) {
    char buffer[BUFFER_MAX];
    while (fgets(buffer, sizeof buffer, stdin)) {
        fputs(buffer, stderr);
        sleep(3);
    }

    return 0;
}