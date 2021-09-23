#include <stdio.h>

int main() {
    enum loop {NO, YES};
    enum loop okloop = YES;

    int i = 0;
    int lim = 1;
    int c = 0;
    int s[10] = {0};
    while (okloop == YES) {
        if (i >= lim - 1) {
            okloop = NO;
        } else if ((c = getchar()) == '\n') {
            okloop = NO;
        } else if (c == EOF) {
            okloop = NO;
        } else {
            s[i] = c;
            ++i;
        }
    }
}