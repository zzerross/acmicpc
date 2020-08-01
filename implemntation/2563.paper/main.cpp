#include <stdio.h>

int main() {
    int A[100][100] = { 0, }, N, Y, X, y, x, s = 0;

    for (scanf("%d", &N); N--;) {
        scanf("%d %d", &X, &Y);

        for (y = Y; y < Y + 10; y++)
            for (x = X; x < X + 10; x++)
                A[y][x] = 1;
    }

    for (y = 0; y < 100; y++)
        for (x = 0; x < 100; x++)
            if (A[y][x])
                s++;

    printf("%d\n", s);

    return 0;
}
