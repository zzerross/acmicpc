#include <stdio.h>

#define W 100
#define V (W + 1)

int A[W][W], N, L = 0, R = 0;
int Y[] = { -1, 0, 1,  0 };
int X[] = {  0, 1, 0, -1 };
int B[W][W][V];

int max(int i, int j) {
    return i < j ? j : i;
}

int range(int i, int j) {
    return 0 <= i && i < W && 0 <= j && j < W;
}

int solve(int i, int j, int l) {
    if (!range(i, j))
        return 0;

    if (B[i][j][l])
        return 0;

    B[i][j][l] = true;

    if (A[i][j] < l)
        return 0;

    for (int d = 0; d < 4; d++)
        solve(i + Y[d], j + X[d], l);

    return 1;
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);

            L = max(L, A[i][j]);
        }
    }

    for (int i, j, r, l = 1; l <= L; l++) {
        for (r = i = 0; i < N; i++)
            for (j = 0; j < N; j++)
                if (solve(i, j, l))
                    r++;

        R = max(R, r);
    }

    printf("%d\n", R);

    return 0;
}
