#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

int buf[BUFSIZE];
int bufp = 0;

int getch(void) { // get a (possibly pushed back) character
    return (bufp > 0) ? : buf[--bufp] : getchar();
}

void ungetch(int c) { // push character back on input
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters");
    } else {
        buf[bufp++] = c;
    }
}

int main() {

}