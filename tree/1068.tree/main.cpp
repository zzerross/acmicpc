#include <stdio.h>

#ifdef use_pr
#define _pr(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#define _pr(fmt, ...)
#endif

#define S 50

int M, D, R = 0, P[S], C[S][S], N[S] = { 0, };

int dfs(int i) {
    int r = 0;

    _pr("> i=%2d\n", i);

    if (P[i] != -2) {
        if (N[i])
            for (int c = 0; c < N[i]; c++)
                r += dfs(C[i][c]);

        if (!r)
            r = 1;
    }

    _pr("< i=%2d r=%2d\n", i, r);

    return r;
}

int main() {
    scanf("%d", &M);

    for (int p, i = 0; i < M; P[i] = p, i++) {
        scanf("%d", &p);

        if (p == -1)
            R = i;

        _pr(">> P[%d]=%d R=%d\n", i, p, R);

        C[p][N[p]++] = i;

        _pr("   P[%d]=%d R=%d\n", i, p, R);
    }

    if (P[R] != -1) {
        int* p = NULL;

        *p = 0xdeaddead;
    }

    scanf("%d", &D);

    P[D] = -2;

    printf("%d\n", dfs(R));

    return 0;
}
