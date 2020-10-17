/**
 * https://www.acmicpc.net/problem/1373
 */

#include <stdio.h>

#define Z 1000001

int main() {
    char S[Z], O[Z];
    int n, r = 0, o = 0;

    scanf("%s", S);

    for (n = 0; S[n]; n++);

    for (int s, i = 0; i < n;) {
        s = (n - 1 - i) % 3;

        r += (S[i++] - '0') << s;

        if (!s) {
            O[o++] = r + '0';
            r = 0;
        }
    }

    O[o] = '\0';

    printf("%s\n", O);

    return 0;
}
