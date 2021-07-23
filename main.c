#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argv, char *argc[]) {
    if (argv < 2) {
        printf("Number of arguments < 2\n");
        exit(EXIT_FAILURE);
    }
    printf("argc[1] =  %s\n", argc[1]);
    if (!fork()) {
        execlp("find", "find", argc[1], "-type", "f", "-name", "*.m*", "|", "cat", ">", "name.txt", NULL);
    }

    printf("Hello, World!\n");
    return 0;
}
