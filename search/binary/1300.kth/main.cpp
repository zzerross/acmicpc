#include <cstdio>

int min(int i, int j) {
    return i < j ? i : j;
}

int main() {
    int N, K, i, c, l, m, h, r;

    scanf("%d %d", &N, &K);

    for (l = 1, h = K; l <= h;) {
        m = (l + h) / 2;

        for (c = i = 0; i < N; i++)
            c += min(m / (i + 1), N);

        if (c < K)
            l = m + 1;
        else
            h = (r = m) - 1;
    }

    printf("%d\n", r);

    return 0;
}
