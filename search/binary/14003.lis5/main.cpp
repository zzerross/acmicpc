/**
 * https://www.acmicpc.net/problem/14003
 */
#include <cstdio>

#define S 1000000

int N, A[S], R[S], P[S] = { 0 };

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
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    int r = 0;

    R[r] = A[r];

    for (int i = 1; i < N; i++) {
        if (R[r] < A[i]) {
            R[++r] = A[i];
            P[i] = r;
        } else {
            int p = lbnd(R, R + r, A[i]) - R;

            R[p] = A[i];
            P[i] = p;
        }
    }

    printf("%d\n", r + 1);

    for (int i = N - 1, p = r; 0 <= i && 0 <= p; i--)
        if (P[i] == p)
            R[p--] = A[i];

    for (int i = 0; i <= r; i++)
        printf("%d ", R[i]);

    printf("\n");

    return 0;
}
