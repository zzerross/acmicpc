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

int N, K, S = 0, A[Z*Z];

void dmp(int* a, int n, const char* s) {
#ifdef use_pr
    _pr("%8s: ", s);

    for (int j = 1; j <= n; j++)
        _pr("%2d ", j);

    for (int i = 0; i < n * n; i++) {
        if (!(i % n))
            _pr("\n%8d: ", i / n + 1);

        _pr("%2d ", a[i]);
    }

    _pr("\n\n");
#endif
}

int main() {
    scanf("%d %d", &N, &K);

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            A[S++] = i * j;

    dmp(A, N, "before");

    std::sort(A, A + S);

    dmp(A, N, "sorted");

    printf("%d\n", A[K-1]); 

    return 0;
}
