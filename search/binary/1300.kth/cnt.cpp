#include <cstdio>
#include <algorithm>

#ifdef use_pr
#define _pr(fmt, ...) printf(fmt, ##__VA_ARGS__)
#endif

#ifndef _pr
#define _pr(fmt, ...)
#endif

#define Z 10000//0

using namespace std;

int N, K = 0;

int min(int i, int j) {
    return i < j ? i : j;
}

#ifdef use_pr
int S = 0, A[Z*Z];

void dmp(int* a, int n, const char* s) {
    _pr("%8s: ", s);

    for (int j = 1; j <= n; j++)
        _pr("%2d ", j);

    _pr("\n");

    for (int i = 0; i < n; i++) {
        _pr("%8d: ", i + 1);

        for (int j = 0; j < n; j++)
            _pr("%2d ", a ? a[i*n+j] : min(K / (i + 1), N));

        _pr("\n");
    }

    _pr("\n");
}
#endif

int main() {
    scanf("%d %d", &N, &K);

#ifdef use_pr
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            A[S++] = i * j;

    // i * j <= K
    // j <= K / i
    dmp(nullptr, N, "K/i");
    dmp(A, N, "before");

    std::sort(A, A + S);

    dmp(A, N, "sorted");
#endif

    return 0;
}
