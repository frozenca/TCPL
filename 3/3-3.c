void expand(const char s1[], char s2[]) {
    int i = 0;
    int j = 0;
    char c = 0;
    while ((c = s1[i++])) {
        if (s1[i] == '-' && s1[i + 1] >= c) {
            i++;
            while (c < s1[i]) {
                s2[j++] = c++;
            }
        } else {
            s2[j++] = c;
        }
    }
    s2[j] = 0;
}

int main() {

}