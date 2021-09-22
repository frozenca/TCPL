#include <stddef.h>
#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int main() {
    size_t len = 0;
    size_t max = 0;
    char line[MAXLINE] = {0};
    char longest[MAXLINE] = {0};

    while (fgets(line, MAXLINE, stdin)) {
        len = strlen(line);
        printf("%zu, %s\n", len, line);
        if (len > max) {
            max = len;
            strcpy(longest, line);
        }
    }
    if (max > 0) {
        printf("%s", longest);
    }
}