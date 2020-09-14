#include <stdio.h>

// #define dbg

#ifdef dbg
#define _pr printf
#else
#define _pr
#endif

#define vs 100

int vn, en, dp[vs+1][vs+1];

void _dp() {
#ifdef dbg
    _pr(" dp: ");

    for (int v = 1; v <= vn; v++)
        _pr("%d ", v);

    _pr("\n");

    for (int u = 1; u <= vn; u++) {
        _pr("%3d: ", u);

        for (int v = 1; v <= vn; v++)
            if (dp[u][v])
                _pr("%d ", dp[u][v]);
            else
                _pr(". ");

        _pr("\n");
    }
#endif
}

int main() {
    scanf("%d %d", &vn, &en);

    for (int i = 1; i <= vn; i++)
        for (int j = 1; j <= vn; j++)
            dp[i][j] = 0;

    for (int e = 1, s, d; e <= en; e++) {
        scanf("%d %d", &s, &d);

        dp[s][d] = dp[d][s] = 1;
    }

    for (int k = 1; k <= vn; k++)
        for (int i = 1; i <= vn; i++)
            for (int j = 1; j <= vn; j++)
                if (!dp[i][j])
                    dp[i][j] = dp[i][k] && dp[k][j];

    _dp();

    int r = 0;

    for (int v = 2; v <= vn; v++)
        if (dp[1][v])
            r++;

    printf("%d\n", r);

    return 0;
}
