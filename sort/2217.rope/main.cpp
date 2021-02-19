#include <stdio.h>

#define WEIGHT (10000 * 100000)
#define ROPES  100001

template <typename T>
T min(T a, T b) {
    return a < b ? a : b;
}

template <typename T>
T max(T a, T b) {
    return a < b ? b : a;
}

template <typename T>
bool prior(T a, T b) {
    return a > b;
}

template <typename T, bool (*P) (T, T)>
void msrt(T* a, int s) {
    T b[s];

    for (int n = 1; n < s; n *= 2) {
        for (int i, j, p = 0; p < s;) {
            int l = p;
            int m = min(p += n, s) - 1;
            int h = min(p += n, s) - 1;

            for (i = l; i <= h; i++)
                b[i] = a[i];

            for (i = l, j = m + 1; i <= m && j <= h;)
                a[l++] = P(b[i], b[j]) ? b[i++] : b[j++];

            while (i <= m)
                a[l++] = b[i++];

            while (j <= h)
                a[l++] = b[j++];
        }
    }
}

int main() {
    int n, a[ROPES], h = 0;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    msrt<int, prior>(a, n);

    for (int i = 0; i < n; i++)
        h = max(h, a[i] * (i + 1));

    printf("%d\n", h);

    return 0;
}
