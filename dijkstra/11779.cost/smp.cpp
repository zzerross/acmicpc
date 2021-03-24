#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#if 4 <= DEBUG
#define CITIES 1000
#define BUSES  100000
#define WEIGHT 100000
#else
#define CITIES 7 // 1000
#define BUSES  9 // 100000
#define WEIGHT 3 // 100000
#endif

#define DIST   (WEIGHT * CITIES)

int max(int a, int b) {
    return a < b ? b : a;
}

int main() {
    srand((unsigned int) time(NULL));

    int N = max(CITIES, rand() % CITIES + 1);
    int L = max(BUSES, rand() % BUSES + 1);
    int u, v;

    printf("%6d\n%6d\n", N, L);

    for (int i = 0; i < L; i++) {
        for (u = rand() % N + 1; u == (v = rand() % N + 1););

        printf("%6d %6d %6d\n", u, v, rand() % WEIGHT);
    }

    for (u = (rand() % N + 1); u == (v = (rand() % N + 1)););

    printf("%6d %6d\n", u, v);

    return 0;
}
