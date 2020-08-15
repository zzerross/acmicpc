#include <stdio.h>

int main() {
#define S 1000000

    int T, N, M, A[S];

    scanf("%d", &T);

    while (T--) {
        scanf("%d", &N);

        for (int i = 0; i < N; i++)
            scanf("%d", &A[i]);

        scanf("%d", &M);

        for (int k, j, i = 0; i < M; i++) {
            scanf("%d", &k);

            for (j = 0; j < N; j++)
                if (A[j] == k)
                    break;

            printf("%d\n", j < N);
        }
    }

    return 0;
}
