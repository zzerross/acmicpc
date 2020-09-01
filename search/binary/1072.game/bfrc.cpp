/**
 * https://www.acmicpc.net/problem/1072
 */

#include <cstdio>

#ifdef use_pr
#define _pr(fmt, ...) printf(fmt, ##__VA_ARGS__)
#endif

#ifndef _pr
#define _pr(fmt, ...)
#endif

#define Z 1000000000

typedef unsigned long long u64;

u64 psnt(u64 y, u64 x) {
    return 100.0 * y / x;
}

int main() {
    u64 X, Y, R, x, y, r;

    scanf("%llu %llu", &X, &Y);

    if (Y < X) {
        r = R = psnt((y = Y), (x = X));

        _pr("%llu / %llu r=%llu R=%llu\n", y, x, r, R);

        do {
            r = psnt(++y, ++x);

            _pr("%llu / %llu r=%llu R=%llu\n", y, x, r, R);
        } while (r <= R);

        printf("%llu\n", (u64) (x - X));
    } else {
        printf("-1\n");
    }

    return 0;
}
