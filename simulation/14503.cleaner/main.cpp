#include <stdio.h>

#define WALL  1
#define CLEAR 2
#define LEFT(i) ((i + 3) % 4)

int Y[] = { -1, 0, 1,  0 };
int X[] = {  0, 1, 0, -1 };

int B[] = { 1,  0, -1, 0 };
int K[] = { 0, -1,  0, 1 };

int H, W, y, x, d, M[50][50];

int main() {
    scanf("%d %d %d %d %d", &H, &W, &y, &x, &d);

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            scanf("%d", &M[i][j]);

    int r = 0;

    for (int l, u, v, i;;) {
        if (!M[y][x]) {
            M[y][x] = CLEAR;
            r++;
        }

        for (l = d, i = 0; i < 4; i++) {
            l = LEFT(l);
            u = y + Y[l];
            v = x + X[l];

            if (!M[u][v]) {
                y = u;
                x = v;
                d = l;
                break;
            }
        }

        if (4 <= i) {
            y = y + B[d];
            x = x + K[d];

            if (M[y][x] == WALL)
                break;
        }
    }

    printf("%d\n", r);

    return 0;
}
