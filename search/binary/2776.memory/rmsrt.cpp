#include <stdio.h>

#define S 1000000

void msrt(int* a, int l, int h) {
    static int b[S];

    if (l >= h)
        return;

    int m  = (l + h) / 2;
    int i = l;
    int j = m + 1;
    int k = l;

    msrt(a, l, m);
    msrt(a, j, h);

    while (i <= m && j <= h)
        b[k++] = a[i] < a[j] ? a[i++] : a[j++];

    while (i <= m)
        b[k++] = a[i++];

    while (j <= h)
        b[k++] = a[j++];

    for (i = 0; i <= h; i++)
        a[i] = b[i];
}

int* lbnd(int* a, int l, int h, const int& k) {
    for (register int m; l < h;) {
        m = (l + h) / 2;

        if (a[m] < k)
            l = m + 1;
        else
            h = m;
    }

    return a + l;
}

int main() {
    int T, N, M, A[S];

    for (scanf("%d", &T); T--;) {
        scanf("%d", &N);

        for (int i = 0; i < N; i++)
            scanf("%d", &A[i]);

        msrt(A, 0, N - 1);

        scanf("%d", &M);

        for (int j; M--;) {
            scanf("%d", &j);

            printf("%d\n", *lbnd(A, 0, N - 1, j) == j);
        }
    }

    return 0;
}
