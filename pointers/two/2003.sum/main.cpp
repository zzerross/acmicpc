/**
 * https://www.acmicpc.net/problem/2003
 */
#include <cstdio>

int main() {
    int N, M, A[10000], r = 0;

    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    for (int s = A[0], l = 0, h = 0; h < N;) {
        if (s < M) {
            s += A[++h];
        } else if (M < s) {
            s -= A[l++];
        } else {
            r++;

            s -= A[l++];
        }
    }

    printf("%d\n", r);

    return 0;
}
