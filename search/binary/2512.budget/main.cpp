#include <stdio.h>

int main() {
    int N, A[100000], X, i, l = 0, m, h = 0, s, r = 0;

    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        scanf("%d", &A[i]);
  
        if (h < A[i])
            h = A[i];
    }

    scanf("%d", &X);

    while (l <= h) {
        m = (l + h) / 2;

        for (s = i = 0; i < N; i++)
            s += (A[i] < m ? A[i] : m);

        if (s <= X) {
            r = m;
            l = m + 1;
        } else {
            h = m - 1;
        }
    }

    printf("%d\n", r);

    return 0;
}
