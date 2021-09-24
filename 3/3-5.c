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

void itob(int n, char s[], int b) {
    int i = 0;
    int sign = n;
    if (sign < 0) {
        n = -n;
    }
    do {
        int j = n % b;
        s[i++] = (char)((j <= 9) ? j + '0' : j + 'a' - 10);
    } while ((n /= b) > 0);
    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = 0;
    reverse(s);
}

int main() {

}