#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

enum { NAME, PARENS, BRACKETS};

void dcl(void);
int gettoken(void);

extern int tokentype;
extern char token[];
extern char name[];
extern char out[];
extern int prevtoken;

void errmsg(const char* msg) {
    printf("%s", msg);
    prevtoken = true;
}

void dirdcl(void) {
    int type = 0;
    if (tokentype == '(') {
        dcl();
        if (tokentype != ')') {
            errmsg("error: missing )\n");
        }
    } else if (tokentype == NAME) {
        strcpy(name, token);
    } else {
        errmsg("error: expected name or (dcl)\n");
    }
    while ((type = gettoken()) == PARENS || type == BRACKETS) {
        if (type == PARENS) {
            strcat(out, " function returning");
        } else {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
    }
}

void dcl(void) {
    int ns = 0;
    for (; gettoken() == '*';) ns++;
    dirdcl();
    while (ns-- > 0) {
        strcat(out, " pointer to");
    }
}

int main() {
}