/**
 * https://www.acmicpc.net/problem/12738
 */

#include <cstdio>

#define S 1000000

int* lbnd(int* l, int* h, int t) {
    while (l < h) {
        int* m = l + ((h - l) / 2);

        if (*m < t)
            l = m + 1;
        else
            h = m;
    }

    return l;
}

int main() {
    int N, A[S], r = 0;

    scanf("%d %d", &N, &A[r]);

    for (int j, i = 1; i < N; i++) {
        scanf("%d", &j);

        if (A[r] < j)
            A[++r] = j;
        else
            *lbnd(A, A + r, j) = j;
    }

    printf("%d\n", r + 1);

    return 0;
}
