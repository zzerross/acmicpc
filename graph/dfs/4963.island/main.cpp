#include <stdio.h>

int W, H, A[50][50];
int Y[] = { -1,  1,  0,  0, -1, -1,  1,  1 };
int X[] = {  0,  0, -1,  1, -1,  1, -1,  1 };

int valid(int i, int j) {
    return 0 <= i && i < H && 0 <= j && j < W;
}

int dfs(int i, int j, int t = 0) {
    if (!valid(i, j))
        return 0;

    if (!A[i][j])
        return 0;

    A[i][j] = 0;

    for (int d = 0; d < 8; d++)
        dfs(i + Y[d], j + X[d], t + 1);

    return 1;
}

int main() {
    while (1) {
        scanf("%d %d", &W, &H);

        if (W == 0 && H == 0)
            break;

        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
                scanf("%d", &A[i][j]);

        int r = 0;

        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
                if (dfs(i, j))
                    r++;

        printf("%d\n", r);
    }

    return 0;
}
