#include <stdio.h>

void echo_quote(int c) {
    int d = 0;
    putchar(c);
    while((d = getchar()) != c) {
        putchar(d);
        if (d == '\\') {
            putchar(getchar());
        }
    }
    putchar(d);
}

void in_comment1(void) {
    int c = getchar();
    int d = getchar();
    while (c != '*' || d != '/') {
        c = d;
        d = getchar();
    }
}
void in_comment2(void) {
    int c = 0;
    while ((c = getchar()) != '\n');
}

void rcomment(int c) {
    int d = 0;
    if (c == '/') {
        if ((d = getchar()) == '*') {
            in_comment1();
        } else if (d == '/') {
            in_comment2();
        } else {
            putchar(c);
            putchar(d);
        }
    } else if (c == '\'' || c == '\"') {
        echo_quote(c);
    } else {
        putchar(c);
    }
}

int main() {
    int c = 0, pos = 0;
    while ((c = getchar()) != EOF) {
        rcomment(c);
    }

}