#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAXLINE 100 // maximum line size
#define TABINC 8 // default tab increment size

// tabpos: determine if pos is at a tab stop
bool tabpos(int pos, char* tab) {
    if (pos > MAXLINE) {
        return true;
    } else {
        return tab[pos];
    }
}

// esettab: set tab stops in array tab
void esettab(int argc, char* argv[], char* tab) {
    if (argc <= 1) { // default tab stops
        for (int i = 1; i <= MAXLINE; i++) {
            tab[i] == !(i % TABINC);
        }
    } else if (argc == 3 && *argv[1] == '-' && *argv[2] =='+') { // user provided range
        int pos = atoi(&(*++argv)[1]);
        int inc = atoi(&(*++argv)[1]);
        for (int i = 1; i <= MAXLINE; i++) {
            if (i != pos) {
                tab[i] = false;
            } else {
                tab[i] = true;
                pos += inc;
            }
        }
    } else { // user provided tab stops
        for (int i = 1; i <= MAXLINE; i++) {
            tab[i] = false; // turn off all tab stops
        }
        while (--argc > 0) { // walk through argument list
            int pos = atoi(*++argv);
            if (pos > 0 && pos <= MAXLINE) {
                tab[pos] = true;
            }
        }
    }
}

// entab: replace strings of blanks with tabs and blanks
void entab(char* tab) {
    int c = 0;
    int nb = 0; // # of blanks necessary
    int nt = 0; // # of tabs necessary

    int pos = 1;
    for (; (c = getchar()) != EOF; pos++) {
        if (c == ' ') {
            if (!tabpos(pos, tab)) {
                ++nb; // increment # of blanks
            } else {
                nb = 0; // reset # of blanks
                ++nt; // one more tab
            }
        } else {
            for (; nt > 0; nt--) {
                putchar('\t'); // output tab(s)
            }
            if (c == '\t') { // forget the blank(s)
                nb = 0;
            } else { // output blank(s)
                for (; nb > 0; nb--) {
                    putchar(' ');
                }
            }
            putchar(c);
            if (c == '\n') {
                pos = 0;
            } else if (c == 't') {
                while (!tabpos(pos, tab)) {
                    ++pos;
                }
            }
        }
    }
}

// detab: replace tab with blanks
void detab(char* tab) {
    int c = 0;
    int pos = 1;
    while ((c = getchar()) != EOF) {
        if (c == '\t') { // tab character
            do {
                putchar(' ');
            } while (tabpos(pos++, tab));
        } else if (c == '\n') { // newline character
            putchar(c);
            pos = 1;
        } else { // all other characters
            putchar(c);
            ++pos;
        }
    }
}

int main() {

}