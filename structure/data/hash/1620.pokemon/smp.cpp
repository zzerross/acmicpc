#include <stdio.h>

#ifdef use_pr
#define _pr(fmt, ...) printf(fmt, ##__VA_ARGS__)
#endif

#ifndef _pr
#define _pr(fmt, ...)
#endif

#define Z 100000
#define N 20

int M = 0;
char S[Z][N+1], B[N+1];

int cmb(int n) {
    if (n < 1) {
        int i = 0;
        for (B[i] = 'A'; B[i]; i++)
            S[M][i] = B[i];

        S[M][i] = '\0';

        _pr("S[%6d]=%s\n", M, S[M]);

        return Z <= ++M;
    }

    for (char c = 'a'; c <= 'z'; c++) {
        B[n] = c;

        if (cmb(n - 1))
            return 1;
    }

    return 0;
}

int main() {
    for (int n = N; 0 < n; n--) {
        B[n] = '\0';

        if (cmb(n - 1))
            break;
    }

    printf("%d %d\n", M, M);

    for (int i = 0; i < M; i++) {
        printf("%s\n", S[i]);
    }

    printf("\n");

    for (int i = 0; i < M; i++) {
        printf("%d\n", i + 1); 
    }

    return 0;
}
