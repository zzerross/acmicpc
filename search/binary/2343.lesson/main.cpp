#include <stdio.h>

typedef unsigned long long u64;

u64 max(u64 a, u64 b) {
    return a < b ? b : a;
}

int main() {
    u64 L, B, T[100000], l = 0, h = 0;

    scanf("%lld %lld", &L, &B);

    for (u64 i = 0; i < L; i++) {
        scanf("%lld", &T[i]);

        l = max(l, T[i]);
        h += T[i];
    }

    for (u64 i, s, b, m; l <= h;) {
        m = l + (h - l) / 2;

        for (i = 0, s = 0, b = 1; i < L && b <= B; i++) {
            if (m < s + T[i]) {
                s = 0;
                if (B < ++b)
                    break;
            }

            s += T[i];
        }

        if (L <= i && b <= B)
            h = m - 1;
        else
            l = m + 1;
    }

    printf("%llu\n", l);

    return 0;
}
