int any(const char s1[], const char s2[]) {
    for (int i = 0; s1[i]; i++) {
        for (int j = 0; s1[j]; j++) {
            if (s1[i] == s2[j]) {
                return i;
            }
        }
    }
    return -1;
}

int main() {

}