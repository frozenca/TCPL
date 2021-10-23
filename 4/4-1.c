#include <string.h>

size_t strrindex(const char s[static 1], const char t[static 1]) {
    for (size_t i = strlen(s) - strlen(t); i >= 0; --i) {
        int k = 0;
        for (size_t j = i; t[k] && s[j] == t[k]; ++j, ++k) ;
        if (k > 0 && !t[k]) {
            return i;
        }
    }
    return -1;
}

int main() {

}