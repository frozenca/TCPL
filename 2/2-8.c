int wordlength(void) {
    unsigned v = ~0;
    int i = 1;
    for (; (v >>= 1) > 0; i++) ;
    return i;
}

unsigned rightrot(unsigned x, int n) {
    int wl = wordlength();
    while (n-- > 0) {
        unsigned rbit = (x & 1) << (wl - 1);
        x >>= 1;
        x |= rbit;
    }
    return x;
}

int main() {

}