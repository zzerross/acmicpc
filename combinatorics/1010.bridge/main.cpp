#include <stdio.h>

#define N 31

int main() {
    int T, n, m, dp[N][N];

    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        scanf("%d %d", &n, &m);

        for (int j = 0; j <= m; j++)
            dp[1][j] = j;

        for (int k, j, i = 2; i <= n; i++)
            for (j = i; j <= m; j++)
                for (dp[i][j] = 0, k = i; k <= j; k++)
                    dp[i][j] += dp[i-1][k-1];

        printf("%d\n", dp[n][m]);
    }

    return 0;
}
