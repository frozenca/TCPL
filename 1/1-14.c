#include <stdio.h>
#include <ctype.h>

static const int MAXHIST = 15;
#define MAXCHAR 128

int main() {
    enum {
        OUT,
        IN
    };

    int c = 0, nc = 0;
    int state = OUT;
    int cc[MAXCHAR] = {0};
    while ((c = getchar()) != EOF) {
        if (c < MAXCHAR) {
            ++cc[c];
        }
    }
    int maxvalue = 0;
    for (int i = 1; i < MAXCHAR; ++i) {
        if (cc[i] > maxvalue) {
            maxvalue = cc[i];
        }
    }

    int len = 0;
    for (int i = 1; i < MAXCHAR; ++i) {
        if (isprint(i)) {
            printf("%5d - %c - %5d : ", i, i, cc[i]);
        } else {
            printf("%5d - %5d : ", i, cc[i]);
        }
        if (cc[i] > 0) {
            if ((len = cc[i] * MAXHIST / maxvalue) <= 0) {
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