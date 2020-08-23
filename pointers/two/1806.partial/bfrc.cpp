/**
 * https://www.acmicpc.net/problem/1806
 */

#include <cstdio>

#define Z 100000

int main() {
    int N, S, A[Z];

    scanf("%d %d", &N, &S);

    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    int m = Z;

    for (int s, n, i = 0; i < N; i++) {
        for (s = 0, n = 0; i + n < N; n++) {
            if (S <= (s += A[i+n])) {
                if (n < m)
                    m = n;

                break;
            }
        }
    }

    printf("%d\n", m == Z ? 0 : m + 1);

    return 0;
}
