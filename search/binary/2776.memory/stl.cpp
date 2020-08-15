#include <cstdio>
#include <algorithm>

int main() {
#define S 1000000

    int T, N, M, A[S];

    for (scanf("%d", &T); T--;) {
        scanf("%d", &N);

        for (int i = 0; i < N; i++)
            scanf("%d", &A[i]);

        std::sort(A, A + N);

        scanf("%d", &M);

        for (int j; M--;) {
            scanf("%d", &j);

            printf("%d\n", *std::lower_bound(A, A + N - 1, j) == j);
        }
    }

    return 0;
}
