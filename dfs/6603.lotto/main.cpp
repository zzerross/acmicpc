#include <stdio.h>

#define S 6

int N, A[50], Q[S];

void dfs(int n = 0, int i = 0) {
    if (S <= n) {
        for (int i = 0; i < n; i++)
            printf("%d ", Q[i]);

        return (void) printf("\n");
    }

    if (N <= i)
        return;

    Q[n] = A[i];

    dfs(n + 1, i + 1);
    dfs(n, i + 1);
}

int main() {
    while (1) {
        scanf("%d", &N);

        if (!N)
            break;

        for (int i = 0; i < N; i++)
            scanf("%d", &A[i]);

        dfs();

        printf("\n");
    }

    return 0;
}
