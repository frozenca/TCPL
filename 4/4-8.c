#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

char buf = 0;

int getch(void) { // get a (possibly pushed back) character
    int c = 0;
    if (buf) {
        c = buf;
    } else {
        c = getchar();
    }
    buf = 0;
    return c;
}

void ungetch(int c) { // push character back on input
    if (buf) {
        printf("ungetch: too many characters\n");
    } else {
        buf = c;
    }
}

int main() {

}