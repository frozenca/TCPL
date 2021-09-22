#include <stddef.h>
#include <stdio.h>
#include <string.h>

static const int TABINC = 8;

int main() {
    int c = 0;
    int pos = 1;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            int nb = TABINC - (pos - 1) % TABINC;
            while (nb > 0) {
                putchar(' ');
                ++pos;
                --nb;
            }
        } else if (c == '\n') {
            putchar(c);
            pos = 1;
        } else {
            putchar(c);
            ++pos;
        }
    }
}