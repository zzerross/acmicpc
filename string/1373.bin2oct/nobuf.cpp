/**
 * https://www.acmicpc.net/problem/1373
 */

#include <stdio.h>

#define Z 1000001

#define B(c) ((c) - '0')

int main() {
    char S[Z];
    int n, i = 0;

    scanf("%s", S);

    for (n = 0; S[n]; n++);

    if (n % 3 == 1)
        printf("%d", S[i++] - '0');

    if (n % 3 == 2)
        printf("%d", ((S[i++] - '0') << 1) + (S[i++] - '0'));

    while (i < n)
        printf("%d", ((S[i++] - '0') << 2) + ((S[i++] - '0') << 1) + S[i++] - '0');
    printf("\n");

    return 0;
}
