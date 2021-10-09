#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

#define DELIMITER "/\n"
//LinkedListOfPath had the scope of concat all path find by shell script
typedef struct LLOfPath {
    char *part;
    struct LLOfPath *next;
} LOP;
typedef struct LLListOfPart {
    struct LLOfPath *this;
    struct LLListOfPart *next;
} ListLOP;

int main() {
    //execution of script (for instruction follow the description)
    if (!fork()) {
        execlp("bash", "bash", "../bash.sh", (char *) NULL);
    }
    FILE *fp = fopen("../name.txt", "r");
    char line[100], *tokstring;
    while (fgets(line, sizeof(line), fp) != NULL) {
        while ((tokstring = strtok(line, DELIMITER)) != NULL) {

        }
        printf("Hello, World!\n");
        return 0;
    }
}