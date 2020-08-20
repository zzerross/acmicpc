#include <cstdio>
#include <cstdlib>
#include <ctime>

#define S 10 // 1000
#define C 1000000000

int main() {
    int n = S;
    int c = C;
    int A[S];

    srand((unsigned int) time(NULL));

    printf("%d %d\n", n, c);

    for (int k = 0, i = 1;; i++) {
        for (int j = 1; j <= i; j++) {
            A[k++] = i;

            if (n <= k)
                goto out;
        }
    }

out:
    for (int i = 0; i < n; i++) {
        int j = rand() % n;
        int t = A[i];
        A[i] = A[j];
        A[j] = t;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);

    printf("\n");

    return 0;
}
