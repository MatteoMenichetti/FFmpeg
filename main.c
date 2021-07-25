#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

struct LinkedList {
    char *token;
    struct LinkedList *next;
};
struct LL {
    struct LinkedList *this;
    struct LL *next;
};

int main(int argv, char *argc[]) {
    if (!fork()) {
        execlp("bash", "bash", "../bash.sh", (char *) NULL);
    }
    FILE *fp = fopen("name.txt", "r");
    struct LinkedList *first, *actual;
    struct LL *list = calloc(1, sizeof(struct LL)), *firstLL=list;
    char line[100];
    while (fgets(line, sizeof(line), fp) != NULL) {
        first = (struct LinkedList *) calloc(1, sizeof(struct LinkedList));
        actual = first;
        printf("first assignment\n");
        actual->token = strtok(line, "/");
        actual->next = (struct LinkedList *) calloc(1, sizeof(struct LinkedList));
        actual = actual->next;
        while ((actual->token = strtok(NULL, "/")) != NULL) {
            printf("next assignment\n");
            actual->next = (struct LinkedList *) calloc(1, sizeof(struct LinkedList));
            actual = actual->next;
        }
        free(actual);
        list->this = first;
        list->next = (struct LL *) calloc(1, sizeof(struct LL));
    }
    for (firstLL = firstLL; firstLL != NULL; firstLL = firstLL->next)printf("%s, ", firstLL->this);
    printf("Hello, World!\n");
    return 0;
}
