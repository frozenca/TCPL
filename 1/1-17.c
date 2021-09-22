#include <stddef.h>
#include <stdio.h>
#include <string.h>

#define MAXLINE 1000
static const size_t LONGLINE = 80;

int main() {
    size_t len = 0;
    char line[MAXLINE] = {0};

    while (fgets(line, MAXLINE, stdin)) {
        len = strlen(line);
        if (len > LONGLINE) {
            printf("%s", line);
        }
    }
}