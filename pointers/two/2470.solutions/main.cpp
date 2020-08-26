/**
 * https://www.acmicpc.net/problem/2470
 */
#include <cstdio>
#include <algorithm>

#define S 100000
#define Z 2000000001

int min(int i, int j) {
    return i < j ? i : j;
}

int abs(int i) {
    return i < 0 ? -i : i;
}

void msrt(int* a, int n) {
    int b[S], i, j;

    for (int s = 1; s < n; s *= 2) {
        for (int p = 0; p < n;) {
            int l = p;
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
    int N, A[S], u, v, a;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    msrt(A, N);

    for (int s, m = Z, l = 0, h = N - 1; l < h;) {
        if ((a = abs(s = (A[l] + A[h]))) < m) {
            u = A[l];
            v = A[h];
            m = a;
        }

        if (s < 0) {
            l++;
        } else if (0 < s) {
            h--;
        } else {
            break;
        }
    }

    printf("%d %d\n", u, v);

    return 0;
}
