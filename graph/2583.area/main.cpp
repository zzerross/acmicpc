#include <stdio.h>

#define W 100
#define Z (W * W)

int dy[] = { -1, 0, 1,  0 };
int dx[] = {  0, 1, 0, -1 };

int M, N, K, B[W][W] = { 0, }, qa[Z], qn = 0;

void dump() {
#ifdef use_pr
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++)
            printf("%c ", B[i][j] ? '0' + B[i][j] : '.');

        printf("\n");
    }
#endif
}

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

            for (i = l, j = m + 1; i <= m && j <= h;)
                a[l++] = b[i] < b[j] ? b[i++] : b[j++];

            while (i <= m)
                a[l++] = b[i++];

            while (j <= h)
                a[l++] = b[j++];
        }
    }
}

int range(int i, int j) {
    return 0 <= i && i < M && 0 <= j && j < N;
}

int dfs(int i, int j) {
    if (!range(i, j))
        return 0;

    if (B[i][j])
        return 0;

    B[i][j] = 2;

    int r = 1;

    for (int d = 0; d < 4; d++)
        r += dfs(i + dy[d], j + dx[d]);

    return r;
}

int main() {
    scanf("%d %d %d", &M, &N, &K);

    for (int a, b, c, d, i = 0; i < K; i++) {
        scanf("%d %d %d %d", &a, &b, &c, &d);

        for (int y = b; y < d; y++)
            for (int x = a; x < c; x++)
                B[y][x] = 1;
    }

    dump();

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if ((qa[qn] = dfs(i, j)))
                qn++;

    msrt(qa, qn);

    printf("%d\n", qn);

    for (int i = 0; i < qn; i++)
        printf("%d ", qa[i]);

    printf("\n");

    dump();

    return 0;
}
