#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXOP 100 // max size of operand or operator
#define MAXVAL 100 // maximum depth of val stack
#define MAXLINE 100
static const char NUMBER = '#'; // signal that a number was found
static const char NAME = '$'; // signal that a name was found

int sp = 0; // next free stack position
double val[MAXVAL]; // value stack

int getop(char s[static 1]) {
    int c = 0;
    size_t len = 0;
    int li = 0;
    char line[MAXLINE] = {0};
    char* ptr = line;
    if (!line[li]) {
        if (!getline(&ptr, &len, stdin)) {
            return EOF;
        } else {
            li = 0;
        }
    }
    while ((s[0] = c = line[li++]) == ' ' || c == '\t') ;
    s[1] = 0;
    int i = 0;
    if (islower(c)) { // command or NAME
        while (islower(s[++i] = c = line[li++])) ;
        s[i] = 0;
        li--;
        if (strlen(s) > 1) {
            return NAME; // >1 char; it is a NAME
        } else {
            return c; // it may be a command
        }
    }
    if (!isdigit(c) && c != '.' && c != '-') {
        return c; // not a number
    }
    if (c == '-') {
        if (isdigit(c = line[li++]) || c == '.') {
            s[++i] = c; // negative number
        } else {
            li--;
            return '-'; // minus sign
        }
    }
    if (isdigit(c)) { // collect integer part
        while (isdigit(s[++i] = c = line[li++]));
    }
    if (c == '.') { // collect fraction part
        while (isdigit(s[++i] = c = line[li++]));
    }
    s[i] = 0;
    li--;
    return NUMBER;
}

int main() {

}