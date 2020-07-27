#include <stdio.h>

int main() {
    int A[100];

    for (int n = 0;; n++) {
        scanf("%d", &A[n]);

        if (A[n] == -1) {
            break;
        } else if (A[n] == 0) {
            int r = 0;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == j)
                        continue;

                    if (A[i] * 2 == A[j])
                        r++;
                }
            }

            printf("%d\n", r);

            n = -1;
        }
    }

    return 0;
}
