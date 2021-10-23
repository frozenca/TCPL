#include <ctype.h>

double atof(const char s[static 1]) {
    int i = 0;
    for (; isspace(s[i]); ++i) ;
    int sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') {
        ++i;
    }
    double val = 0.0;
    for (; isdigit(s[i]); ++i) {
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.') {
        ++i;
    }
    double power = 1.0;
    for (; isdigit(s[i]); ++i) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    val = sign * val / power;

    if (s[i] == 'e' || s[i] == 'E') {
        sign = (s[++i] == '-') ? 1 : -1;
        if (s[i] == '+' || s[i] == '-') {
            ++i;
        }
        int exp = 0;
        for (; isdigit(s[i]); ++i) {
            exp = 10 * exp + (s[i] - '0');
        }
        if (sign == 1) {
            while (exp-- > 0) {
                val *= 10;
            }
        } else {
            while (exp-- > 0) {
                val /= 10;
            }
        }
    }
    return val;
}

int main() {

}