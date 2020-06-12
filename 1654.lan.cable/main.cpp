/**
 * @ref https://www.acmicpc.net/problem/1654
 */

#include <stdio.h>

typedef long long i64;

template <typename T, int S>
void msrt(T* a, int l, int h) {
    static T b[S];

    if (l >= h)
        return;

    int m = (l + h) / 2;
    int i = l;
    int j = m + 1;
    int k = l;

    msrt<T, S>(a, l, m);
    msrt<T, S>(a, m + 1, h);

    while (i <= m && j <= h)
        b[k++] = a[i] < a[j] ? a[i++] : a[j++];

    while (i <= m)
        b[k++] = a[i++];

    while (j <= h)
        b[k++] = a[j++];

    for (i = l; i <= h; i++)
        a[i] = b[i];
}

int main() {
#define S 10000

    int K, N;
    i64 A[S];

    scanf("%d %d", &K, &N);

    for (int i = 0; i < K; i++)
        scanf("%llu", &A[i]);

    msrt<i64, S>(A, 0, K - 1);

    i64 l = 1;
    i64 h = A[K-1];

    for (int n, i; l <= h;) {
        i64 m = (l + h) / 2;

        for (n = 0, i = 0; i < K; i++)
            n += A[i] / m;

        if (N <= n)
            l = m + 1;
        else
            h = m - 1;
    }

    printf("%llu\n", h);

    return 0;
}
