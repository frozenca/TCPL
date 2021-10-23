#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXOP 100 // max size of operand or operator
#define MAXVAL 100 // maximum depth of val stack
#define BUFSIZE 100
static const char NUMBER = '#'; // signal that a number was found

int sp = 0; // next free stack position
double val[MAXVAL]; // value stack

char buf[BUFSIZE]; // buffer for ungetch
int bufp = 0; // next free position in buf

void push(double f) { // push f onto value stack
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("error: stack full, can't push %g\n", f);
    }
}

double pop(void) { // pop and return top value from stack
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int getch(void) { // get a (possibly pushed back) character
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(char c) { // push character back on input
    if (bufp >= BUFSIZE) {
        printf("ungetch too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}

int getop(char s[static 1]) {
    int c = 0;
    while ((s[0] = c = getch()) == ' ' || c == '\t') ;
    s[1] = 0;
    if (!isdigit(c) && c != '.' && c != '-') {
        return c; // not a number
    }
    int i = 0;
    if (c == '-') {
        if (isdigit(c = getch()) || c == '.') {
            s[++i] = c; // negative number
        } else {
            if (c != EOF) {
                ungetch(c);
            }
            return '-'; // minus sign
        }
    }
    if (isdigit(c)) { // collect integer part
        while (isdigit(s[++i] = c = getch()));
    }
    if (c == '.') { // collect fraction part
        while (isdigit(s[++i] = c = getch()));
    }
    s[i] = 0;
    if (c != EOF) {
        ungetch(c);
    }
    return NUMBER;
}

// clear: clear the stack
void clear(void) {
    sp = 0;
}

// reverse Polish calculator
int main() {
    int type = 0;
    double op1 = 0.0;
    double op2 = 0.0;
    char s[MAXOP] = {0};

    while ((type = getop(s)) != EOF) {
        switch(type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0) {
                    push(pop() / op2);
                } else {
                    printf("error: zero divisor\n");
                }
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0) {
                    push(fmod(pop(), op2));
                } else {
                    printf("error: zero divisor\n");
                }
                break;
            case '?': // print top element of the stack
                op2 = pop();
                printf("\t%.8g\n", op2);
                push(op2);
                break;
            case 'c': // clear the stack
                clear();
                break;
            case 'd': // duplicate top element of the stack
                op2 = pop();
                push(op2);
                push(op2);
                break;
            case 's': // swap the top two elements
                op1 = pop();
                op2 = pop();
                push(op1);
                push(op2);
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }

}