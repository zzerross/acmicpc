#include <stdio.h>

int N, M, A[5][5], B[2][5][5], m;

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);

            B[0][i][j] = A[i][j];
        }
    }

    for (m = 1; m < M; m++) {
        for (int i = 0; i < N; i++) {
            for ( int j = 0; j < N; j++) {
                B[m%2][i][j] = 0;

                for (int x = 0; x < N; x++)
                    B[m%2][i][j] =
                        (B[m%2][i][j] + (B[(m-1)%2][i][x] * A[x][j]) % 1000) % 1000;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", B[(m-1)%2][i][j]);

        printf("\n");
    }

    return 0;
}
