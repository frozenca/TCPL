int bitcount(unsigned x) {
    int b = 0;
    for (; x != 0; x &= x - 1) {
        ++b;
    }
    return b;
}

int main() {

}