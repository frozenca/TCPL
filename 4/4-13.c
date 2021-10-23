#include <string.h>

void reverser(char s[static 1], int i, int len) {
    int c = 0;
    int j = len - (i + 1);
    if (i < j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        reverser(s, ++i, len);
    }
}

void reverse(char s[static 1]) {
    reverser(s, 0, strlen(s));
}

int main() {

}