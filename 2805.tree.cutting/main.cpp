/**
 * @ref https://www.acmicpc.net/problem/2805
 */

#include <stdio.h>

typedef unsigned long long u64;

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
#define S 1000000

    int N;
    u64 M, A[S];

    scanf("%d %llu", &N, &M);

    for (int i = 0; i < N; i++)
        scanf("%llu", &A[i]);

    msrt<u64, S>(A, 0, N - 1);

    u64 l = 1;
    u64 h = A[N-1];
    u64 c;

    for (int i; l <= h;) {
        u64 m = (l + h) / 2;

        for (i = 0, c = 0ULL; i < N; i++)
            if (m < A[i])
                c += (A[i] - m);

        if (M <= c)
            l = m + 1;
        else
            h = m - 1;
    }

    printf("%llu\n", h);

    return 0;
}
