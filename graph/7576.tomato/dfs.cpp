#include <stdio.h>

#define Z 1000

int W, H, A[Z][Z];
int Y[] = { 1, -1,  0, 0 };
int X[] = { 0,  0, -1, 1 };

void dump() {
#if 0
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++)
            printf("%2d ", A[i][j]);

        printf("\n");
    }
#endif
}

int rng(int i, int j) {
    return 0 <= i && i < H && 0 <= j && j < W;
}

int dfs(int i, int j, int t) {
    if (!rng(i, j))
        return 0;

    if (A[i][j] == t) {
        A[i][j] = t + 1;

        int r = 0;

        for (int d = 0; d < 4; d++)
            r += dfs(i + Y[d], j + X[d], t);

        return r;
    } else if (A[i][j] == 0) {
        return !!(A[i][j] = t + 1);
    }

    return 0;
}

int main() {
    scanf("%d %d", &W, &H);

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            scanf("%d", &A[i][j]);

    int i, j, r, t, s = 0;

    for (t = 1, r = 1; r; t++)
        for (r = 0, i = 0; i < H; i++)
            for (j = 0; j < W; j++)
                if (A[i][j] == t)
                    r += dfs(i, j, t);

    dump();

    for (i = 0; i < H; i++)
        for (j = 0; j < W; j++)
            if (!A[i][j])
                s++;

    printf("%d\n", s ? -1 : t - 2);

    return 0;
}
