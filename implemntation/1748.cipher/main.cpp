#include <stdio.h>

//        123456789
#define S 100000000
#define C 11

int N, r, s, c, n, A[C] = { 0, 1, };

int count(int n) {
    int c, i, j;

    for (c = 0, i = 0; i <= n; i++)
        for (j = i; j; j /= 10, c++);

    return c;
}

int solve(int n, int c = 1, int m = 10) {
    if (n < 1)
        return 0;

    int r = n % m;

    // 123456789 10 11 12
    // 1 * 9     2 * 3

    // 432 %  10 =  +2
    // 430 % 100 = +30 = 30 * 2 
    return r * c + solve(n - r, c + 1, m * 10);
}

int main() {
    //     1~9: 1 x (  9 -   1 + 1) = 1 x   9
    //   10~99: 2 x ( 99 -  10 + 1) = 2 x  90
    // 100~200: 3 x (
    // 100~999: 3 x (999 - 100 + 1) = 3 x 900
    //
    //     543: 3 x (543 - 100 + 1) = N % 100 + 1
    //          2 x ( 99 -  10 + 1) = N
    //          1 x (  9 -   1 + 1)

    for (int i = 2; i < C; i++)
        A[i] = A[i-1] * 10;

    scanf("%d", &N);

    for (c = 1, n = N; n /= 10; c++);
    printf("N=%3d A[%d]=%d\n", N, c, A[c]);

    r = N % A[c];
    N = N - r;
    s = c * (N - A[c] + 1);
    s = s + (40 * 2) + 3;

    printf("N=%3d r=%3d s=%d\n", N, r, s);

    for (; 0 < c;) {
        s += (A[--c] * 9);
        printf("c=%3d %d s=%d\n", c, A[c] * 9, s);
    }

    printf("count()=%d\n", count(N));

    //printf("%d\n", solve(N));

    return 0;
}
