#include <stdlib.h>

// strncpy: copy n characters from t to s
void strncpy(char* restrict s, char* restrict t, size_t n) {
    while (*t && n--) {
        *s++ = *t++;
    }
    while (n--) {
        *s++ = 0;
    }
}

// strncat: concatenate n characters of t to the end of s
void strncat(char* restrict s, char* restrict t, size_t n) {
    size_t strlen(const char* str);
    strncpy(s + strlen(s), t, n);
}

// strncmp: compare at most n characters of t with s
int strncmp(const char* s, const char* t, size_t n) {
    for (; *s == *t; s++, t++) {
        if (!*s || n--) {
            return 0;
        }
    }
    return *s - *t;
}

int main() {

}