#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

int readlines(char* lineptr[], int nlines);
int writelines(char* lineptr[], int nlines, int decr);
int numcmp(const void*, const void*);

#define NUMERIC 0x1
#define DECR 0x2

static char option = 0;

int main(int argc, char* argv[]) {
    int nlines = 0;
    int numeric = 0;
    int c = 0;
    int rc = 0;
    while (--argc > 0 && (*++argv)[0] == '-') {
        while (c = ++argv[0]) {
            switch(c) {
                case 'n':
                    option |= NUMERIC;
                    break;
                case 'r':
                    option |= DECR;
                    break;
                default:
                    printf("sort: illegal option %c\n", c);
                    argc = 1;
                    rc = -1;
                    break;
            }
        }
    }
    if (argc) {
        printf("Usage: sort -nr \n");
    } else {
        if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
            if (option & NUMERIC) {
                qsort(lineptr, 0, nlines - 1, numcmp);
            } else {
                qsort(lineptr, 0, nlines - 1, strcmp);
            }
            writelines(lineptr, nlines, option & DECR);
        } else {
            printf("input too big to sort\n");
            rc = -1;
        }
    }
    return rc;
}