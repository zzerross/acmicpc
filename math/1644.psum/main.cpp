/**
 * https://www.acmicpc.net/problem/1644
 */

#include <cstdio>

#define S 4000001

int P[S] = { 0, }, N, i, j, r = 0, n = 0, s;

int main() {
    for (i = 2; i < S; i++) {
        if (!P[i]) {
            P[n++] = i;

            for (j = i + i; j < S; j += i)
                P[j] = 1;
        }
    }

    scanf("%d", &N);

    for (s = P[0], i = 0, j = 0; i <= j && j < n && P[j] <= N;) {
        if (s < N) {
            s += P[++j];
        } else {
            if (s == N)
                r++;

            s -= P[i++];
        }
    }

    printf("%d\n", r);

    return 0;
}
