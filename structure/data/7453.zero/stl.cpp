#include <cstdio>
#include <algorithm>

#define S 4000
#define Z (S * S)
#define M 4

int A[S][M], X[Z], Y[Z], N;

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            scanf("%d", &A[i][j]);

    int n = 0;
    unsigned long long r = 0LU;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++, n++) {
            X[n] = A[i][0] + A[j][1];
            Y[n] = A[i][2] + A[j][3];
        }
    }

    std::sort(Y, Y + n);

    for (int i = 0; i < n; i++) {
        int* l = std::lower_bound(Y, Y + n, -X[i]);
        int* h = std::upper_bound(Y, Y + n, -X[i]); 

        if (l != h)
            r += h - l;
    }

    printf("%llu\n", r);

    return 0;
}
