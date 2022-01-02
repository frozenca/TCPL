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
    void parmdcl(void);
    if (tokentype == '(') {
        dcl();
        if (tokentype != ')') {
            errmsg("error: missing )\n");
        }
    } else if (tokentype == NAME) {
        if (!name[0]) {
            strcpy(name, token);
        }
    } else {
        prevtoken = true;
    }
    while ((type = gettoken()) == PARENS || type == BRACKETS || type == '(') {
        if (type == PARENS) {
            strcat(out, " function returning");
        } else if (type == '(') {
            strcat(out, " function expecting");
            parmdcl();
            strcat(out, " and returning");
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