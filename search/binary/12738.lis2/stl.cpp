/**
 * https://www.acmicpc.net/problem/12738
 */

#include <cstdio>
#include <algorithm>

#define S 1000000

int main() {
    int N, A[S], r = 0;

    scanf("%d %d", &N, &A[r]);

    for (int j, i = 1; i < N; i++) {
        scanf("%d", &j);

        if (A[r] < j)
            A[++r] = j;
        else
            *std::lower_bound(A, A + r, j) = j;
    }

    printf("%d\n", r + 1);

    return 0;
}
