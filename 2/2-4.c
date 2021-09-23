#include <stdio.h>

void squeeze(char s1[], const char s2[]) {
    int k = 0;
    for (int i = 0; s1[i]; i++) {
        int j = 0;
        for (j = 0; s2[j] && s2[j] != s1[i]; j++) ;
        if (s2[j]) {
            s1[k++] = s1[i];
        }
    }
    s1[k] = 0;
}

int main() {

}