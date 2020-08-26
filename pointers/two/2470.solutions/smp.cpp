#include <cstdio>
#include <ctime>
#include <cstdlib>

#define S 100000
#define Z 1000000000

int main() {
    srand((unsigned int) time(NULL));

    int N = S;

    printf("%d\n", N);
    
    for (int i = 0; i < N; i++)
        printf("%d ", (rand() % 2 ? 1 : -1) * (rand() % (Z + 1)));

    printf("\n");

    return 0;
}
