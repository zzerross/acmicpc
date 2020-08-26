/**
 * https://www.acmicpc.net/problem/1978
 */
#include <cstdio>

#define S 1001

int main() {
    int N, P[S] = { 1, 1, 0, }, i, j, r = 0;

    for (i = 2; i < S; i++)
        for (j = i + i; j < S; j += i)
            P[j] = 1;

    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf("%d", &j);

        r += !P[j];
    }

    printf("%d\n", r);

    return 0;
}
