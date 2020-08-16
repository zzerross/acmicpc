#include <stdio.h>

#define S 4000
#define M 4

int A[S][M], N, i, j, k, l, r = 0;

int main() {
    scanf("%d", &N);

    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
            scanf("%d", &A[i][j]);

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            for (k = 0; k < N; k++)
                for (l = 0; l < N; l++)
                    r += !(A[i][0] + A[j][1] + A[k][2] + A[l][3]);

    printf("%d\n", r);

    return 0;
}
