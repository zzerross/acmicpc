#include <stdio.h>

#define N 30

int dp[N][N];

int cmb(int i, int j) {
    if (i == j || i < 1)
        return 1;

    int& r = dp[i][j];

    if (r != -1)
        return r;

    r = 0;

    return r = cmb(i - 1, j - 1) + cmb(i, j - 1);
}

int main() {
    int T, n, m;

    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        scanf("%d %d", &n, &m);

        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                dp[i][j] = -1;

        printf("%d\n", cmb(n, m));
    }

    return 0;
}
