#include <stdio.h>

typedef long long i64;

i64 abs(i64 i) {
    return 0 < i ? i : -i;
}

i64 sqr(i64 i) {
    return i * i;
}

int main() {
    i64 T, x1, y1, r1, x2, y2, r2;

    for (scanf("%lld", &T); 0 < T; T--) {
        scanf("%lld %lld %lld %lld %lld %lld", &x1, &y1, &r1, &x2, &y2, &r2);

        i64 z = sqr(x1 - x2) + sqr(y1 - y2);
        i64 s = sqr(r1 + r2);
        i64 d = sqr(r1 - r2);
        i64 r = 0;

        if (z == 0) {
            r = r1 == r2 ? -1 : 0;
        } else {
            if (d < z && z < s)
                r = 2;
            else if (z == d || z == s)
                r = 1;
            else if (z < d || s < z)
                r = 0;
            else
                printf("r=%lld\n", r);
        }

        printf("%lld\n", r);
    }

    return 0;
}
