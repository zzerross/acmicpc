#include <stdio.h>

#define Z 500000
int N, A[Z], M, T;

template <typename T, int S>
void msrt(T* a, int l, int h) {
    static T b[S];

    if (l >= h)
        return;

    int m = (l + h) / 2;
    int i = l;
    int j = m + 1;
    int k = l;

    msrt<T, S>(a, l, m);
    msrt<T, S>(a, m + 1, h);

    while (i <= m && j <= h)
        b[k++] = a[i] < a[j] ? a[i++] : a[j++];

    while (i <= m)
        b[k++] = a[i++];

    while (j <= h)
        b[k++] = a[j++];

    for (i = l; i <= h; i++)
        a[i] = b[i];
}

int has(int t, int l, int h) {
    for (int m; l <= h;) {
        m = (l + h) / 2;

        if (A[m] < t)
            l = m + 1;
        else if (t < A[m])
            h = m - 1;
        else
            return 1;
    }

    return 0;
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
        scanf("%d", &A[i]);

    msrt<int, Z>(A, 0, N - 1);

    scanf("%d", &M);

    for (int i = 0; i < M; i++) {
        scanf("%d", &T);

        printf("%d ", has(T, 0, N - 1));
    }

    return 0;
}
