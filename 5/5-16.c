#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAXLINES 5000
char *lineptr[MAXLINES];

#define NUMERIC 0x1
#define DECR 0x2
#define FOLD 0x4
#define DIR 0x8

static char option = 0;

int readlines(char* lineptr[], int nlines);
int writelines(char* lineptr[], int nlines, int decr);
int numcmp(const void*, const void*);
int charcmp(const void* s, const void* t) {
    char a, b;
    bool fold = (option & FOLD);
    bool dir = (option & DIR);
    const char* cs = s;
    const char* ct = t;
    do {
        if (dir) {
            while (!isalnum(*cs) && *cs != ' ' && *cs) {
                cs++;
            }
            while (!isalnum(*ct) && *ct != ' ' && *ct) {
                ct++;
            }
        }
        a = fold ? tolower(*cs) : *cs;
        cs++;
        b = fold ? tolower(*ct) : *ct;
        ct++;
        if (a == b && !a) {
            return 0;
        }
    } while (a == b);
    return a - b;
}

int main(int argc, char* argv[]) {
    int nlines = 0;
    int numeric = 0;
    int c = 0;
    int rc = 0;
    while (--argc > 0 && (*++argv)[0] == '-') {
        while (c = ++argv[0]) {
            switch(c) {
                case 'd':
                    option |= DIR;
                    break;
                case 'f':
                    option |= FOLD;
                    break;
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
        printf("Usage: sort -dfnr \n");
    } else {
        if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
            if (option & NUMERIC) {
                qsort(lineptr, 0, nlines - 1, numcmp);
            } else {
                qsort(lineptr, 0, nlines - 1, charcmp);
            }
            writelines(lineptr, nlines, option & DECR);
        } else {
            printf("input too big to sort\n");
            rc = -1;
        }
    }
    return rc;
}