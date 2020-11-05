#include <stdio.h>

#define S 1000000

int N, M = 1, A[S], B[S];

int min(int i, int j) {
    return i < j ? i : j;
}

void msrt(int* a, int n) {
    for (int s = 1; s < n; s *= 2) {
        for (int p = 0; p < n;) {
            static int b[S], i, j;

            int l = p;
            int m = min(p += s, n) - 1;
            int h = min(p += s, n) - 1;

            for (int i = l; i <= h; i++)
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

int lbnd(int* a, int n, int t) {
    int l, h;

    for (l = 0, h = n - 1; l < h;) {
        int m = l + (h - l) / 2;

        if (a[m] < t)
            l = m + 1;
        else
            h = m;
    }

    return l;
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; B[i] = A[i], i++)
        scanf("%d" ,&A[i]);

    msrt(B, N);

    for (int i = 1; i < N; i++)
        if (B[i-1] != B[i])
            B[M++] = B[i];

    for (int i = 0; i < N; i++)
        printf("%d ", lbnd(B, M, A[i]));

    printf("\n");

    return 0;
}
