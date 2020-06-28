#include <stdio.h>

int main() {
    int N, M;

    scanf("%d %d", &N, &M);

    for (int s = N * M, j, i = 0; i < 5; i++) {
        scanf("%d", &j);

        printf("%d ", j - s);
    }

    return 0;
}
