#include <stddef.h>
#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int remove_blanks(char* s) {
    int i = 0;
    while (s[i] != '\n') {
        ++i;
    }
    --i;
    while (i >= 0 && (s[i] == ' ' || s[i] == '\t')) {
        --i;
    }
    if (i >= 0) {
        ++i;
        s[i] = '\n';
        ++i;
        s[i] = '\0';
    }
    return i;
}

int main() {
    char line[MAXLINE] = {0};

    while (fgets(line, MAXLINE, stdin)) {
        if (remove_blanks(line) > 0) {
            printf("%s", line);
        }
    }
}