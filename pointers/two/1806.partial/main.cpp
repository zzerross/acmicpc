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

    for (int l = 0, r = 0, s = A[0], n = 1; l <= r && r < N;) {
        if (S <= s) {
            if (n < m)
                if ((m = n) == 1)
                    break;

            s -= A[l++];
            n--;
        } else {
            s += A[++r];
            n++;
        }
    }

    printf("%d\n", m == Z ? 0 : m);

    return 0;
}
