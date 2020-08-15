#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
#define T 10
#define S 10 // 1000000
    setbuf(stdout, NULL);

    srand((unsigned int) time(NULL));

    int A[S];
    int t = rand() % T + 1;

    printf("%d\n", t);

    while (t--) {
        int N = (rand() % S) + 1;

        printf("%d\n", N);

        for (int i = 0; i < N; i++)
            A[i] = rand();

        for (int i = 0; i < N; i++)
            printf("%d ", A[i]);

        int M = rand() % S + 1;

        printf("\n%d\n", M);

        for (int i = 0; i < M; i++)
            printf("%d ", ((rand() % 2) ? 1 : -1) * (i % 4 ? A[rand()%N] : rand()));

        printf("\n");
    }

    return 0;
}
