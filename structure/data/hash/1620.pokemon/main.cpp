#include <stdio.h>

#define Z 100001
#define D 65001
#define Q 10
#define C ('Z' - 'A' + 2)
#define _i(c) (c - 'a' + 1)
#define _I(c) (c - 'A' + 1)

char S[Z][21], T[21];
int N, M, H[C][D][Q] = { 0, }, L[C][D] = { 0, };

int _strcmp(char* a, char* b) {
    int i = 0;

    for (; a[i] && b[i] && a[i] == b[i]; i++);

    return a[i] - b[i];
}

int _atoi(char* s) {
    int r = 0;

    for (int i = 0; s[i]; i++)
        r = (r * 10) + s[i] - '0';

    return r;
}

int hash(char* s) {
    int r = 0;

    for (int i = 1; s[i]; i++)
        r = r * C + _i(s[i]);

    return r % D;
}

int main() {
    scanf("%d %d", &N, &M);

    for (int t = 0; t < N; t++) {
        scanf("%s", S[t]);

        int i = _I(*S[t]);
        int h = hash(S[t]);

        H[i][h][L[i][h]++] = t;
    }

    for (int t = 0; t < M; t++) {
        scanf("%s", T);

        if (*T <= '9') {
            printf("%s\n", S[_atoi(T)-1]);
        } else {
            int i = _I(*T);
            int h = hash(T);

            for (int l = 0; l < L[i][h]; l++)
                if (!_strcmp(T, S[H[i][h][l]]))
                    printf("%d\n", H[i][h][l] + 1);
        }
    }

    return 0;
}
