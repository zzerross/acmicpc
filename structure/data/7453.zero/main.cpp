#include <cstdio>
#include <algorithm>

#define S 4000
#define Z (S * S)
#define M 4

int A[S][M], X[Z], Y[Z], N;

int min(int& i, int& j) {
    return i < j ? i : j;
}

void msrt(int* a, int n) {
    for (int s = 1; s < n; s *= 2) {
        for (int p = 0; p < n;) {
            static int b[Z], i, j;
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

int* bnd(int* a, int l, int h, int t, bool u) {
    while (l < h) {
        int m = (l + h) / 2;

        if (a[m] < t || (u && a[m] == t))
            l = m + 1;
        else
            h = m;
    }

    return a + l;
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &A[i][j]);

    int n = 0;
    unsigned long long r = 0LU;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++, n++) {
            X[n] = A[i][0] + A[j][1];
            Y[n] = A[i][2] + A[j][3];
        }
    }

    msrt(Y, n);

    for (int i = 0; i < n; i++) {
        int* l = bnd(Y, 0, n, -X[i], false);
        int* h = bnd(Y, 0, n, -X[i], true);

        if (l != h)
            r += h - l;
    }

    printf("%llu\n", r);

    return 0;
}
