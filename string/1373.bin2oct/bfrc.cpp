/**
 * https://www.acmicpc.net/problem/1373
 */

#include <stdio.h>

#define Z 1000001

int main() {
    char S[Z];
    int R[Z], n, r = 0, s = 0;

    scanf("%s", S);

    for (n = 0; S[n]; n++);

    for (int i = 0; i < n;) {
        if (S[n-i-1] == '1')
            r |= (1 << (i % 3));

        if (!(++i % 3)) {
            R[s++] = r;
            r = 0;
        }
    }

    if (r || !s)
        R[s++] = r;

    for (int i = s - 1; 0 <= i; i--)
        printf("%c", R[i] + '0');

    printf("\n");

    return 0;
}
