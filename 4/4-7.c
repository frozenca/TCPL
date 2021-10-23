#include <stdio.h>
#include <string.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

void ungetch(int c) { // push character back on input
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}

// ungets: push string back onto the input
void ungets(const char s[static 1]) {
    size_t len = strlen(s);
    while (len > 0) {
        ungetch(s[--len]);
    }
}

int main() {

}