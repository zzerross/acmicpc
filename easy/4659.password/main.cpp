#include <stdio.h>

static bool isVowel(char c) {
    switch (c) {
        case 'a': case 'e': case 'i': case 'o': case 'u':
            return true;
        default:
            return false;
    }
}

bool valid(char* s) {
    bool v = false;

    for (int i = 0; s[i]; i++) {
        if (isVowel(s[i]))
            v = true;

        if (0 < i)
            if (s[i-1] == s[i])
                if (s[i] != 'e' && s[i] != 'o')
                    return false;
        
        if (1 < i) {
            if (isVowel(s[i-2]) && isVowel(s[i-1]) && isVowel(s[i])) {
                return false;
            } else if (!isVowel(s[i-2]) && !isVowel(s[i-1]) && !isVowel(s[i])) {
                return false;
            }
        }
    }

    return v;
}


int main() {
    for (char s[21]; scanf("%s", s);) {
        if (s[0] == 'e' && s[1] == 'n' && s[2] == 'd' && s[3] == '\0')
            break;

        printf("<%s> is%s acceptable.\n", s, valid(s) ? "" : " not");
    }

    return 0;
}
