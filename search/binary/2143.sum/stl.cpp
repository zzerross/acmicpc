#include <cstdio>
#include <algorithm>

#define S 1000
#define Z (S * S)

int T, N, A[S], M, B[S], C[Z], D[Z];

int sum(int* a, int* b, int n) {
    int k = 0;

    for (int i = 0; i < n; i++) {
        a[k++] = b[i];

        for (int j = i + 1; j < n; j++, k++)
            a[k] = a[k-1] + b[j];
    }

    return k;
}

int main() {
    scanf("%d", &T);

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    scanf("%d", &M);

    for (int i = 0; i < M; i++)
        scanf("%d", &B[i]);

    int n = sum(C, A, N);
    int m = sum(D, B, M); 

    std::sort(D, D + m);

    long long r = 0;

    for (int i = 0; i < n; i++) {
        int d = T - C[i];

        int* u = std::upper_bound(D, D + m, d);
        int* l = std::lower_bound(D, D + m, d);

        r += (u - l);
    }

    printf("%lld\n", r);

    return 0;
}
