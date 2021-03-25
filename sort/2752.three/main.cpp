#include <stdio.h>

int min(int a, int b) {
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

            for (i = 0; i <= h; i++)
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
    int A[3], N = sizeof(A) / sizeof(A[0]);

    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    sort(A, N);

    for (int i = 0; i < N; i++)
        printf("%d ", A[i]);

    printf("\n");

    return 0;
}
