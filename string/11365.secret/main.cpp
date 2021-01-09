#include <stdio.h>

int main() {
    char s[501];

    for (int i = 0, n;; i++) {
        s[i] = getchar();

        if (i == 2 && s[0] == 'E' && s[1] == 'N' && s[2] == 'D')
            break;

        if (s[i] == '\n' || s[i] == '\r') {
            for (s[i] = n = 0; s[n]; n++)
                ;

            while (0 <= --n)
                printf("%c", s[n]);

            printf("\n");

            i = -1;
        }
    }

    return 0;
}
