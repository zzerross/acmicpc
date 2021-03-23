#include <stdio.h>

#define H (1000000000 * 2)

int N, A[100000], y, x;

int abs(int a) {
    return a < 0 ? -a : a;
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    for (int i = 0, b = H; i < N - 1; i++) {
        for (int l = i + 1, h = N - 1; l <= h;) {
            int m = l + (h - l) / 2;

            if (abs(A[i] + A[m]) < b)
                b = abs(A[y = i] + A[x = m]);

            if (A[m] < -A[i])
                l = m + 1;
            else if (-A[i] < A[m])
                h = m - 1;
            else
                goto out;
        }
    }

out:
    printf("%d %d\n", A[y], A[x]);

    return 0;
}
