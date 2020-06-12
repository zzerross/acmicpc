/**
 * @ref https://www.acmicpc.net/problem/2110
 * @ref https://geehye.github.io/baekjoon-2110/#
 */
#include <stdio.h>

typedef unsigned int u32;

template <typename T, int S>
void msrt(T* a, int l, int h) {
    T b[S];

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
#define S 200000

    int N, C;
    u32 A[S];

    scanf("%d %d", &N, &C);

    for (int i = 0; i < N; i++)
        scanf("%u", &A[i]);

    msrt<u32, S>(A, 0, N - 1);

    u32 l = 1U;
    u32 h = A[N-1] - A[0];

    while (l <= h) {
        int c = 1;
        u32 m = (l + h) / 2;

        for (int p = 0, i = 0; i < N; i++) {
            if (m <= A[i] - A[p]) {
                c++;
                p = i;
            }
        }

        if (C <= c)
            l = m + 1;
        else
            h = m - 1;
    }

    printf("%u\n", h);

    return 0;
}
