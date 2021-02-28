#include <stdio.h>

#define S 5000000

int min(int i, int j) {
    return i < j ? i : j;
}

int main() {
    int N, K, *A, *b;

    scanf("%d %d", &N, &K);

    A = new int[N];
    b = new int[N];

    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    for (int i, j, n = 1; n < N; n *= 2) {
        for (int p = 0; p < N;) {
            int l = p;
            int m = min(p += n, N) - 1;
            int h = min(p += n, N) - 1;

            for (i = l; i <= h; i++)
                b[i] = A[i];

            for (i = l, j = m + 1; i <= m && j <= h;)
                A[l++] = b[i] < b[j] ? b[i++] : b[j++];

            while (i <= m)
                A[l++] = b[i++];

            while (j <= h)
                A[l++] = b[j++];
        }
    }

    printf("%d\n", A[K-1]);

    delete[] A;
    delete[] b;

    return 0;
}
