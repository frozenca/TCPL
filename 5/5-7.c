#include <stdio.h>
#include <string.h>

#define MAXLEN 1000 // maximum length of line
static const size_t MAXSTOR = 5000; // size of available storage space

// readlines: read input lines
int readlines(char* lineptr[], char* linestor, int maxlines) {
    int len = 0;
    char line[MAXLEN] = {0};
    char* p = linestor;
    char* linestop = linestor + MAXSTOR;

    int nlines = 0;
    while ((len = getline(line, MAXLEN, stdin)) > 0) {
        if (nlines >= maxlines || p + len > linestop) {
            return -1;
        } else {
            line[len - 1] = 0; // delete newline
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    }
    return nlines;

}

int main() {

}
