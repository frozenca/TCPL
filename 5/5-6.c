#include <stdio.h>
#include <string.h>
#include <ctype.h>

// getlin: read a line into s, return length
int getlin(char* s, size_t lim) {
    int c = 0;
    char* t = s;
    while (--lim && (c = getchar()) != EOF && c != '\n') {
        *s++ = c;
    }
    if (c == '\n') {
        *s++ = c;
    }
    *s = 0;
    return s - t;
}

// atoi: convert s to integer; pointer version
int atoi(const char* s) {
    int n = 0;
    for (; isspace(*s); s++); // skip whitespace
    int sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-') { // skip sign
        s++;
    }
    for (n = 0; isdigit(*s); s++) {
        n = 10 * n + (*s - '0');
    }
    return sign * n;
}

// reverse: reverse string s in place
void reverse(char* s) {
    int c = 0;
    char* t = 0;
    for (t = s + (strlen(s) - 1); s < t; s++, t--) {
        c = *s;
        *s = *t;
        *t = c;
    }
}

// itoa: convert n to characters in s; pointer version
void itoa(int n, char* s) {
    int sign = 0;
    char* t = s; // save pointer to s
    if ((sign = n) < 0) { // record sign
        n = -n; // make n positive
    }
    do { // generate digits in reverse order
        *s++ = n % 10 + '0'; // get next digit
    } while ((n /= 10) > 0); // delete it
    if (sign < 0) {
        *s++ = '-';
    }
    *s = 0;
    reverse(t);
}

// strindex: return index of t in s, -1 if none
int strindex(const char* s, const char* t) {
    char* b = s;
    for (; *s; s++) {
        char* p = 0;
        char* r = 0;
        for (p = s, r = t; r && *p == *r; p++, r++) ;
        if (r > t && !*r) {
            return s - b;
        }
    }
    return -1;
}

// atof: convert string s to float; pointer version
float atof(const char* s) {
    for (; isspace(*s); s++); // skip whitespace
    int sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-') {
        s++;
    }
    float val = 0.0f;
    for (; isdigit(*s); s++) {
        val = 10.0f * val + (*s - '0');
    }
    if (*s == '.') {
        s++;
    }
    float power = 1.0f;
    for (; isdigit(*s); s++) {
        val = 10.0f * val + (*s - '0');
        power *= 10.0f;
    }
    return sign * val / power;
}

static const char NUMBER = '0';

int getch(void);
void ungetch(int);

// getop: get next operator or numeric operand; pointer version
int getop(char* s) {
    int c = 0;
    while ((*s = c = getch()) == ' ' || c == '\t') ;
    *(s + 1) = 0;
    if (!isdigit(c) && c != '.') {
        return c; // not a number
    }
    if (isdigit(c)) { // collect integer part
        while (isdigit(*++s = c = getch())) ;
    }
    if (c == '.') { // collect fraction part
        while (isdigit(*++s = c = getch())) ;
    }
    *s = 0;
    if (c != EOF) {
        ungetch(c);
    }
    return NUMBER;
}

// getop

int main() {

}