#include <stdio.h>

#define S 1001
#define Z (S * (S - 1) / 2)

int N, M, Q[S][Z], L[S] = { 0, }, R = 0, V[S] = { 0, };

int dfs(int u) {
    if (V[u])
        return 0;

    V[u] = 1;

    for (int i = 0; i < L[u]; i++)
        dfs(Q[u][i]);

    return 1;
}

int main() {
    printf("%d %d Q=%lumb\n", S, Z, sizeof(Q) / (1024 * 1024));

    scanf("%d %d", &N, &M);

    for (int u, v, i = 0; i < M; i++) {
        scanf("%d %d", &u, &v);

        Q[u][L[u]++] = v;
        Q[v][L[v]++] = u;
    }

    for (int u = 1; u <= N; u++)
        if (dfs(u))
            R++;

    printf("%d\n", R);

    return 0;
}
