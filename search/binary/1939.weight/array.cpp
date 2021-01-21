#include <stdio.h>

#define S 10001
#define Z 10000//0

#ifdef use_pr
#define _pr(fmt, ...) printf(fmt, ##__VA_ARGS__)
#endif

#ifndef _pr
#define _pr(fmt, ...)
#endif

int N, M, R[S][Z], W[S][Z], C[S] = { 0, };
bool V[S];

int max(int i, int j) {
    return i < j ? j : i;
}

bool dfs(int i, int e, int w) {
    _pr("-> i=%d e=%d w=%d V=%d\n", i, e, w, V[i]);

    if (V[i])
        return false;

    V[i] = true;

    if (i == e)
        return true;

    for (int j = 0; j < C[i]; j++)
        if (w <= W[i][j])
            if (dfs(R[i][j], e, w))
                return true;

    return false;
}

int main() {
    scanf("%d %d", &N, &M);

    int s, e, l = 0, h = 0;

    for (int a, b, w, i = 0; i < M; i++, h = max(h, w)) {
        scanf("%d %d %d", &a, &b, &w);

        W[a][C[a]] = w;
        R[a][C[a]++] = b;
        W[b][C[b]] = w;
        R[b][C[b]++] = a;
    }

    scanf("%d %d", &s, &e);

    while (l <= h) {
        for (int i = 0; i <= N; i++)
            V[i] = false;

        int m = (l + h) / 2;
        _pr("l=%d h=%d m=%d> \n", l, h, m);

        if (dfs(s, e, m))
            l = m + 1;
        else
            h = m - 1;
        _pr("l=%d h=%d m=%d< \n", l, h, m);
    }

    printf("%d\n", h);

    return 0;
}
