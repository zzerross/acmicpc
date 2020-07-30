#include <stdio.h>

#define S 10001

int main() {
    int A[S], I, J, i, j, k, m, n;

    while (1) {
        scanf("%d %d", &I, &J);

        if (!I)
            break;

        for (i = 0; i < S; i++)
            A[i] = 0;

        for (m = n = i = 0; i < I; i++) {
            for (j = 0; j < J; j++) {
                scanf("%d", &k);

                if (A[m] < ++A[k])
                    m = k;
            }
        }

        for(i = 1; i < S; i++)
            if (i != m)
                if (n < A[i])
                    n = A[i];

        for (i = 1; i < S; i++)
            if (n == A[i])
                printf("%d ", i);

        printf("\n");
    }

    return 0;
}
