#include <stdio.h>

static const int TABINC = 8;

int main() {
    int c = 0;
    int nb = 0;
    int nt = 0;
    for (int pos = 1; (c = getchar()) != EOF; ++pos) {
        if (c == ' ') {
            if (pos % TABINC != 0) {
                ++nb;
            } else {
                nb = 0;
                ++nt;
            }
        } else {
            for (; nt > 0; --nt) {
                putchar('\t');
            }
            if (c == '\t') {
                nb = 0;
            } else {
                for (; nb > 0; --nb) {
                    putchar(' ');
                }
            }
            putchar(c);
            if (c == '\n') {
                pos = 0;
            } else if (c == '\t') {
                pos += (TABINC - (pos - 1) % TABINC) - 1;
            }
        }
    }
}