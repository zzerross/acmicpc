#include <stdio.h>

template <typename T>
T min(T a, T b) {
    return a < b ? a : b;
}

template <typename T>
void sort(T* a, int n) {
    T b[n];

    for (int s = 1; s < n; s *= 2) {
        for (int p = 0; p < n;) {
            int l = p, i, j;
            int m = min(p += s, n) - 1;
            int h = min(p += s, n) - 1;

            for (i = l; i <= h; i++)
                b[i] = a[i];

            for (i = l, j = m + 1; i <= m && j <= h;)
                a[l++] = b[i] < b[j] ? b[i++] : b[j++];

            while (i <= m)
                a[l++] = b[i++];

            while (j <= h)
                a[l++] = b[j++];
        }
    }
}

int main() {
    int M, N, L, A[100000], X[100000], Y[100000], r = 0;

    scanf("%d %d %d", &M, &N, &L);

    for (int i = 0; i < M; i++)
        scanf("%d", &A[i]);

    sort(A, M);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &X[i], &Y[i]);

        int u = X[i] - (L - Y[i]);
        int v = X[i] + (L - Y[i]);

        for (int l = 0, h = M - 1; l <= h;) {
            int m = l + (h - l) / 2;

            if (u <= A[m] && A[m] <= v) {
                r++;
                break;
            } else if (A[m] < u) {
                l = m + 1;
            } else {
                h = m - 1;
            }
        }

    }

    printf("%d\n", r);

    return 0;
}
