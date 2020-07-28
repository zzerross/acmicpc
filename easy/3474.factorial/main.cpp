#include <stdio.h>

int main() {
    int T, N, t, f, i;

    for (scanf("%d", &T); T--;) {
        scanf("%d", &N);

        // 9! = 362880
        // 9 / 2 = 4
        // 9 / 4 = 2
        // 9 / 8 = 1
        for (t = 0, i = 2; i <= N; i *= 2)
            t += N / i;

        // 9 /  5 = 1
        for (f = 0, i = 5; i <= N; i *= 5)
            f += N / i;

        printf("%d\n", t < f ? t : f);
    }

    return 0;
}
