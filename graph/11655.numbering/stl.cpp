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

int dfs(int i, int j) {
    if (!rng(i, j))
        return 0;

    if (A[i][j] == '0')
        return 0;

    A[i][j] = '0';

    int r = 1;

    for (int d = 0; d < 4; d++) {
        int y = i + Y[d];
        int x = j + X[d];

        r += dfs(y, x);
    }

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

    std::sort(Q, Q + q);

    for (int i = 0; i < q; i++)
        printf("%d\n", Q[i]);

    return 0;
}
