#include <stdio.h>

static const int MAXHIST = 15;
#define MAXWORD 11

int main() {
    enum {
        OUT,
        IN
    };

    int c = 0, nc = 0;
    int state = OUT;
    int ovflow = 0;
    int wl[MAXWORD] = {0};
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
            if (nc > 0) {
                if (nc < MAXWORD) {
                    ++wl[nc];
                } else {
                    ++ovflow;
                }
            }
        } else if (state == OUT) {
            state = IN;
            nc = 1;
        } else {
            ++nc;
        }
    }
    int maxvalue = 0;
    for (int i = 1; i < MAXWORD; ++i) {
        if (wl[i] > maxvalue) {
            maxvalue = wl[i];
        }
    }

    int len = 0;
    for (int i = 1; i < MAXWORD; ++i) {
        printf("%5d - %5d : ", i, wl[i]);
        if (wl[i] > 0) {
            if ((len = wl[i] * MAXHIST / maxvalue) <= 0) {
                len = 1;
            }
        } else {
            len = 0;
        }
        while (len > 0) {
            putchar('*');
            --len;
        }
        putchar('\n');
    }
    if (ovflow > 0) {
        printf("There are %d words >= %d\n", ovflow, MAXWORD);
    }


}