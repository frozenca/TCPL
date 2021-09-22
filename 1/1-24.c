#include <stdio.h>

int brace, brack, paren;

void in_quote(int c) {
    int d = 0;
    while ((d = getchar()) != c) {
        if (d == '\\') {
            getchar();
        }
    }
}

void in_comment1(void) {
    int c = getchar();
    int d = getchar();
    while (c != '*' || d != '/') {
        c = d;
        d = getchar();
    }
}
void in_comment2(void) {
    int c = 0;
    while ((c = getchar()) != '\n');
}

void search(int c) {
    if (c == '{') {
        ++brace;
    } else if (c == '}') {
        --brace;
    } else if (c == '[') {
        ++brack;
    } else if (c == ']') {
        --brack;
    } else if (c == '(') {
        ++paren;
    } else if (c == ')') {
        --paren;
    }
}

int main() {
    int c = 0;

    while ((c = getchar()) != EOF) {
        if (c == '/') {
            if ((c = getchar()) == '*') {
                in_comment1();
            } else if (c == '/') {
                in_comment2();
            } else {
                search(c);
            }
        } else if (c == '\'' || c == '\"') {
            in_quote(c);
        } else {
            search(c);
        }
        if (brace < 0) {
            printf("Unbalanced braces!\n");
            brace = 0;
        } else if (brack < 0) {
            printf("Unbalanced brackets!\n");
            brack = 0;
        } else if (paren < 0) {
            printf("Unbalanced parentheses!\n");
            paren = 0;
        }
    }
    if (brace > 0) {
        printf("Unbalanced braces!\n");
    }
    if (brack > 0) {
        printf("Unbalanced brackets!\n");
    }
    if (paren > 0) {
        printf("Unbalanced parentheses!\n");
    }

}