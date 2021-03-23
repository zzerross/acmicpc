#include <stdio.h>

int abs(int a) {
    return a < 0 ? -a : a;
}

int main() {
    int N, A[100000], u, v, r = 1000000000 * 2;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    for (int i = 0, j = N - 1; i < j;) {
        int s = A[i] + A[j];
        int a = abs(s);
        if (a < r) {
            r = a;
            u = A[i];
            v = A[j];
        }

        if (!s) {
            break;
        } else if (s < 0) {
            i++;
        } else {
            j--;
        }
    }

    printf("%d %d\n", u, v);

    return 0;
}
