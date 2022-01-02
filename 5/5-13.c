#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DEFLINES 10 // default # of lines to print
#define LINES 100 // max # of lines to print
#define MAXLEN 100 // max length of an input line

void error(const char* s) {
    printf("%s\n", s);
    exit(1);
}

int main(int argc, char* argv[]) {
    char line[MAXLEN] = {0};
    int n = 0;
    if (argc == 1) {
        n = DEFLINES;
    } else if (argc == 2 && (*++argv)[0] == '-') {
        n = atoi(argv[0] + 1);
    } else {
        error("usage: tail [-n]");
    }
    if (n < 1 || n > LINES) {
        n = LINES;
    }
    char* lineptr[LINES] = {0};
    char* buf = 0;
    char* p = 0;
    if (!(p = buf = malloc(LINES * MAXLEN))) {
        error("tail: cannot allocate buf");
    }
    char* bufend = buf + LINES * MAXLEN;
    int last = 0;
    int nlines = 0;
    int len = 0;
    while ((len = getline(line, MAXLEN, stdin)) > 0) {
        if (p + len + 1 >= bufend) {
            p = buf;
        }
        lineptr[last] = p;
        strcpy(lineptr[last], line);
        if (++last >= LINES) {
            last = 0;
        }
        p += len + 1;
        nlines++;
    }
    if (n > nlines) {
        n = nlines;
    }
    int first = last - n;
    if (first < 0) {
        first += LINES;
    }
    for (int i = first; n-- > 0; i = (i + 1) % LINES) {
        printf("%s", lineptr[i]);
    }

}