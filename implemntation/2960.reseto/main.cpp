#include <stdio.h>

int N, K, A[1001] = { 0, };

int main() {
    scanf("%d %d", &N, &K);

    for (int k = 0, i = 2; i <= N; i++)
        for (int j = i; j <= N; j += i)
            if (!A[j])
                if ((A[j] = ++k) == K)
                    return !printf("%d\n", j);

    return 0;
}
