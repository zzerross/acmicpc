#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define S 50

int main() {
    srand((unsigned int) time(NULL));

    int M = rand() % (S + 1), P[S];

    for (int i = 0; i < M; i++)
        P[i] = rand() % M;

    P[rand() % M] = -1;

    printf("%d\n", M);

    for (int i = 0; i < M; i++)
        printf("%d ", P[i]);

    printf("\n%d\n", rand() % M);

    return 0;
}
