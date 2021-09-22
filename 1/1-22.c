#include <stdio.h>
#include <string.h>

#define MAXCOL 10
static const int TABINC = 8;

char line[MAXCOL];

void printl(int pos) {
    for (int i = 0; i < pos; ++i) {
        putchar(line[i]);
    }
    if (pos > 0) {
        putchar('\n');
    }
}

int exptab(int pos) {
    line[pos] = ' ';
    for (++pos; pos < MAXCOL && pos % TABINC != 0; ++pos) {
        line[pos] = ' ';
    }
    if (pos < MAXCOL) {
        return pos;
    } else {
        printl(pos);
        return 0;
    }
}

int findblank(int pos) {
    while (pos > 0 && line[pos] != ' ') {
        --pos;
    }
    if (pos == 0) {
        return MAXCOL;
    } else {
        return pos + 1;
    }
}

int newpos(int pos) {
    if (pos <= 0 || pos >= MAXCOL) {
        return 0;
    } else {
        int i = 0;
        for (int j = 0; j < MAXCOL; ++j) {
            line[i] = line[j];
            ++i;
        }
        return i;
    }
}

int main() {
    int c = 0, pos = 0;
    while ((c = getchar()) != EOF) {
        line[pos] = (char)c;
        if (c == '\t') {
            pos = exptab(pos);
        } else if (c == '\n') {
            printl(pos);
            pos = 0;
        } else if (++pos >= MAXCOL) {
            pos = findblank(pos);
            printl(pos);
            pos = newpos(pos);
        }
    }

}