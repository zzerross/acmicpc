#include <stdio.h>
#include <stdlib.h>

int N, A[100000], M = 1;

int abs(int a) {
    return a < 0 ? -a : a;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a < b ? b : a;
}

void msrt(int* a, int n) {
    int i, j, b[n];

    for (int s = 1; s < n; s *= 2) {
        for (int p = 0; p < n;) {
            int l = p;
            int m = min(p += s, n) - 1;
            int h = min(p += s, n) - 1;

            for (i = l; i <= h; i++)
                b[i] = a[i];

            for (i = l, j = m + 1; i <= m && j <= h;)
                a[l++] = abs(b[i]) < abs(b[j]) ? b[i++] : b[j++];

            while (i <= m)
                a[l++] = b[i++];

            while (j <= h)
                a[l++] = b[j++];
        }
    }
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    msrt(A, N);

    for (int i = 1; i < N; i++)
        if (abs(A[i-1] + A[i]) < abs(A[M-1] + A[M]))
            M = i;

    printf("%d %d\n", min(A[M-1], A[M]), max(A[M-1], A[M]));

    return 0;
}
