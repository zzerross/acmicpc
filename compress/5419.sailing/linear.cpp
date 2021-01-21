#include <stdio.h>

#ifdef use_pr
#define _pr(fmt, ...) printf(fmt, ##__VA_ARGS__)
#endif

#ifndef _pr
#define _pr(fmt, ...)
#endif

#define S 75000

int N, M, Y[S], X[S], R[S], YMIN, YMAX, XMIN, XMAX;

void dump() {
#ifdef use_pr
    for (int i = YMIN; i <= YMAX; i++) {
        for (int j = XMIN; j <= XMAX; j++) {
            for (int k = 0; k < M; k++) {
                if (i == Y[k] && j == X[k]) {
                    _pr("X ");

                    goto out;
                }
            }

            _pr(". ");
out:
            ;
        }

        _pr("\n");
    }
#endif
}

int abs(int i) {
    return i < 0 ? -i : i;
}

int min(int i, int j) {
    return i < j ? i : j;
}

int max(int i, int j) {
    return i < j ? j : i;
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &M);

        for (int j = 0; j < M; j++) {
            scanf("%d %d", &Y[j], &X[j]);

            R[j] = 0;
#ifdef use_pr
            YMIN = min(YMIN, Y[j]);
            XMIN = min(XMIN, Y[j]);
            YMAX = max(YMAX, X[j]);
            XMAX = max(XMAX, X[j]);
#endif
        }

        dump();

        int r = 1;

        for (int j = 0; j < M; j++, r++) {
            for (int k = 0; k < M; k++) {
                if (R[k])
                    continue;

                if (abs(Y[j] - Y[k]) == abs(X[j] - X[k]))
                    R[k] = r;
            }
        }

        printf("%d\n", r);
    }

    return 0;
}
