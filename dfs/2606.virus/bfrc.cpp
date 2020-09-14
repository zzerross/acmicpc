#include <stdio.h>

#define S 101

int N, M, A[S][S] = { 0, }, V[S] = { 0, }, R = 0;

void solve(int i) {
    V[i] = 1;

    for (int j = 2; j <= N; j++)
        if (!V[j] && A[i][j])
            solve(j);
}

int main() {
    scanf("%d %d", &N, &M);

    for (int i, j; M--; A[i][j] = A[j][i] = 1)
        scanf("%d %d", &i, &j);

    solve(1);

    for (int i = 2; i <= N; i++)
        if (V[i])
            R++;

    printf("%d\n", R);

    return 0;
}
