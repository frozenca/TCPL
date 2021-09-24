void escape(char s[], const char t[]) {
    int j = 0;
    for (int i = 0; t[i]; i++) {
        switch(t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }
    s[j] = 0;
}

void unescape(char s[], const char t[]) {
    int j = 0;
    for (int i = 0; t[i]; i++) {
        switch(t[i]) {
            case '\\':
                switch(t[++i]) {
                    case 'n':
                        s[j++] = '\n';
                        break;
                    case 't':
                        s[j++] = '\t';
                        break;
                    default:
                        s[j++] = '\\';
                        s[j++] = t[i];
                        break;
                }
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }
    s[j] = 0;
}

int main() {

}