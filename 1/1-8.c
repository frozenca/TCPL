#include <stdio.h>

int main() {
    int c = 0;
    int nb = 0, nt = 0, nl = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++nb;
        }
        if (c == '\t') {
            ++nt;
        }
        if (c == '\n') {
            ++nl;
        }
    }
    printf("%d %d %d\n", nb, nt, nl);
}