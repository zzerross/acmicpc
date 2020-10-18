/**
 * https://www.acmicpc.net/problem/11655
 */
#include <cstdio>
#include <algorithm>

#define Z 25

int Y[] = { 1, -1,  0, 0 };
int X[] = { 0,  0, -1, 1 };
int N, Q[Z*Z], q = 0;
char A[Z][Z+1];

bool rng(int i, int j) {
    return 0 <= i && i < N && 0 <= j && j < N;
}

int min(int i, int j) {
    return i < j ? i : j;
}

void msrt(int* a, int n) {
    for (int s = 1; s < n; s *= 2) {
        for (int p = 0; p < n;) {
            int b[Z*Z], i, j;
            int l = p;
            int m = min(p += s, n) -1;
            int h = min(p += s, n) -1;

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

int dfs(int i, int j) {
    if (!rng(i, j))
        return 0;

    if (A[i][j] == '0')
        return 0;

    A[i][j] = '0';

    int r = 1;

    for (int d = 0; d < 4; d++)
        r += dfs(i + Y[d], j + X[d]);

    return r;
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%s", A[i]);

    for (int n, i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if ((n = dfs(i, j)))
                Q[q++] = n;

    printf("%d\n", q);

    msrt(Q, q);

    for (int i = 0; i < q; i++)
        printf("%d\n", Q[i]);

    return 0;
}
