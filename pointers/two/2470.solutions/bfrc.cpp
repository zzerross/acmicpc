#include <cstdio>

#define S 100000
#define Z 1000000000

int abs(int i) {
    return 0 < i ? i : -i;
}

int main() {
    int N, A[S], a, b;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    for (int s, m = Z + 1, i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if ((s = abs(A[i] + A[j])) < m) {
                if (A[i] < A[j]) {
                    a = A[i], b = A[j], m = s;
                } else {
                    a = A[j], b = A[i], m = s;
                }
            }
        }
    }

    printf("%d %d\n", a, b);

    return 0;
}
