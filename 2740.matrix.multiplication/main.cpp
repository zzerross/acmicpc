/**
 * @ref https://www.acmicpc.net/problem/2740
 */

#include <stdio.h>

int main() {
    int Y[2], X[2], M[3][100][100], m, i, j, x;

    for (m = 0; m < 2; m++) {
        scanf("%d %d", &Y[m], &X[m]);

        for (i = 0; i < Y[m]; i++)
            for (j = 0; j < X[m]; j++)
                scanf("%d", &M[m][i][j]);
    }

    for (m = 0, i = 0; i < Y[m]; i++) {
        for (j = 0; j < X[m+1]; j++) {
            M[m+2][i][j] = 0;

            for (x = 0; x < X[m]; x++)
                /*
                 * i x j
                 */
                M[m+2][i][j] += M[m][i][x] * M[m+1][x][j];

            printf("%d ", M[m+2][i][j]);
        }

        printf("\n");
    }

    return 0;
}
