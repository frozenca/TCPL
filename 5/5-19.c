#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS};

void dcl(void);
int gettoken(void);
int nexttoken(void);

extern int tokentype;
extern char token[];
extern char name[];
extern char out[];
extern int prevtoken;

int main(void) {
    int type = 0;
    char temp[MAXTOKEN] = {0};

    while (gettoken() != EOF) {
        strcpy(out, token);
        while ((type = gettoken()) != '\n') {
            if (type == PARENS || type == BRACKETS) {
                strcat(out, token);
            } else if (type == '*') {
                if ((type == nexttoken()) == PARENS || type == BRACKETS) {
                    sprintf(temp, "(*%s)", out);
                } else {
                    sprintf(temp, "*%s", out);
                }
                strcpy(out, temp);
            } else if (type == NAME) {
                sprintf(temp, "%s %s", token, out);
                strcpy(out, temp);
            } else {
                printf("invalid input at %s\n", token);
            }
        }
        printf("%s\n", out);
    }
}