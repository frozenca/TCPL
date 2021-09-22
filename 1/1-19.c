#include <stddef.h>
#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void reverse(char* s) {
    int i = 0;
    while (s[i] != '\0') {
        ++i;
    }
    --i;
    if (s[i] == '\n') {
        --i;
    }
    int j = 0;
    while (j < i) {
        char temp = s[i];
        s[j] = s[i];
        s[i] = temp;
        --i;
        ++j;
    }
}

int main() {
    char line[MAXLINE] = {0};

    while (fgets(line, MAXLINE, stdin)) {
        reverse(line);
        printf("%s", line);
    }
}