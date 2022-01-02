// strcat: concatenate t to the end of s: pointer version
void strcat(char* restrict s, char* restrict t) {
    while (*s) s++;
    while ((*s++ = *t++));
}

int main() {

}