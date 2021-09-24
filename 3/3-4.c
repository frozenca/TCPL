inline int abs(int x) {
    return (x < 0) ? -x : x;
}

void reverse(char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        ++i;
    }
    --i;
    if (s[i] == '\n') {
        --i;
    }
    int j = 0;
    while (j < i) {
        char temp = s[i];
        s[j] = s[i];
        s[i] = temp;
        --i;
        ++j;
    }
}

void itoa(int n, char s[]) {
    int i = 0;
    int sign = n;
    do {
        s[i++] = (char)(abs(n % 10) + '0');
    } while ((n /= 10));
    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = 0;
    reverse(s);
}

int main() {

}