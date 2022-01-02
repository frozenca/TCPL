#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);

// getfloat: get next floating-point number from input
int getfloat(float* pn) {
    int c = 0;
    while (isspace(c = getch())); // skip whitespace
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
        ungetch(c); // it's not a number
        return 0;
    }
    int sign = (c == '-') ? -1 : 1;
    for (*pn = 0.0f; isdigit(c); c = getch()) {
        *pn = 10.0f * *pn + (c - '0'); // integer part
    }
    if (c == '.') {
        c = getch();
    }
    float power = 0.0f;
    for (power = 1.0f; isdigit(c); c = getch()) {
        *pn = 10.0f * *pn + (c - '0'); // fractional part
        power *= 10.0f;
    }
    *pn *= sign / power; // final number
    if (c != EOF) {
        ungetch(c);
    }
    return c;
}

int main() {

}