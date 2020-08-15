#include <stdio.h>

#define S 1000000

int min(const int& i, const int& j) {
    return i < j ? i : j;
}

void msrt(int* a, int n) { 
    for (int s = 1; s < n; s *= 2) {
        for (int p = 0; p < n;) {
            int b[S], i, j;
            int l = p;
            int m = min(p += s, n) - 1;
            int h = min(p += s, n) - 1;

            for (i = l; i <= h; i++)
                b[i] = a[i];

            for (i = l, j = m + 1; i <= m && j <= h;)
                a[l++] = b[i] <= b[j] ? b[i++] : b[j++];

            while (i <= m)
                a[l++] = b[i++];

            while (j <= h)
                a[l++] = b[j++];
        }
    }
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

        msrt(A, N);

        scanf("%d", &M);

        for (int j; M--;) {
            scanf("%d", &j);

            printf("%d\n", *lbnd(A, 0, N - 1, j) == j);
        }
    }

    return 0;
}
