#include <stdio.h>

#define WALL  1
#define CLEAR 2
#define LEFT(i) ((i + 3) % 4)

int Y[] = { -1, 0, 1,  0 };
int X[] = {  0, 1, 0, -1 };

int B[] = { 1,  0, -1, 0 };
int K[] = { 0, -1,  0, 1 };

int H, W, y, x, D, M[50][50];

int clean(int y, int x, int d) {
    if (M[y][x] == WALL)
        return 0;

    int r = 0;

    if (!M[y][x]) {
        M[y][x] = CLEAR;
        r++;
    }

    for (int u, v, l = d, i = 0; i < 4; i++) {
        l = LEFT(l);
        u = y + Y[l];
        v = x + X[l];

        if (!M[u][v])
            return r + clean(u, v, l);
    }

    return r + clean(y + B[d], x + K[d], d);
}

int main() {
    scanf("%d %d %d %d %d", &H, &W, &y, &x, &D);

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            scanf("%d", &M[i][j]);

    printf("%d\n", clean(y, x, D));

    return 0;
}
