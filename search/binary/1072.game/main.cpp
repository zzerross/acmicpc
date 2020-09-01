/**
 * https://www.acmicpc.net/problem/1072
 */

#include <cstdio>

#define Z 1000000000

typedef long long i64;

i64 psnt(i64 y, i64 x) {
    return y * 100 / x;
}

int main() {
    i64 X, Y, P, r;

    scanf("%lld %lld", &X, &Y);

    if ((P = psnt(Y, X) + 1) < 100) {
        for (i64 l = 1, h = Z; l <= h;) {
            i64 m = (l + h ) / 2;
            i64 p = psnt(Y + m, X + m);

            if (p < P) {
                l = m + 1;
            } else {
                h = m - 1;
                r = m;
            }
        }
    } else {
        r = -1;
    }

    printf("%lld\n", r);

    return 0;
}
