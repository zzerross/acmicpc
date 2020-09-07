#include <cstdio>

#define S 1000
#define Z (S * S)

int T, N, A[S], M, B[S], C[Z], D[Z];

int min(int i, int j) {
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

            for (i = l, j = m + 1;  i <= m && j <= h;)
                a[l++] = b[i] < b[j] ? b[i++] : b[j++];

            while (i <= m)
                a[l++] = b[i++];

            while (j <= h)
                a[l++] = b[j++];
        }
    }
}

int* lbnd(int* l, int* h, int t) {
    while (l < h) {
        int* m = l + (h - l) / 2;

        if (*m < t)
            l = m + 1;
        else
            h = m;
    }

    return l;
}

int* ubnd(int* l, int* h, int t) {
    while (l < h) {
        int* m = l + (h - l) / 2;

        if (*m <= t)
            l = m + 1;
        else
            h = m;
    }

    return l;
}

int sum(int* a, int* b, int n) {
    int k = 0;

    for (int i = 0; i < n; i++) {
        a[k++] = b[i];

        for (int j = i + 1; j < n; j++, k++)
            a[k] = a[k-1] + b[j];
    }

    return k;
}

int main() {
    scanf("%d", &T);

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    scanf("%d", &M);

    for (int i = 0; i < M; i++)
        scanf("%d", &B[i]);

    int n = sum(C, A, N);
    int m = sum(D, B, M); 

    msrt(D, m);

    long long r = 0;

    for (int i = 0; i < n; i++) {
        int d = T - C[i];

        int* u = ubnd(D, D + m, d);
        int* l = lbnd(D, D + m, d);

        r += (u - l);
    }

    printf("%lld\n", r);

    return 0;
}
