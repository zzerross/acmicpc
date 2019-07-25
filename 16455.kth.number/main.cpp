#include <stdio.h>
#include <algorithm>
#include <vector>

void swp(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void qst(int *a, int l, int h) {
    if (l >= h)
        return;

    int i = l;
    int j = h;
    int p = h;

    while (1) {
        while (i < p && a[i] <= a[p]) i++;
        while (p < j && a[p] <  a[j]) j--;

        if (i >= j)
            break;

        swp(&a[i], &a[j]);
    }

    swp(&a[i], &a[p]);

    qst(a, l, p - 1);
    qst(a, p + 1, h);
}

void hpy(int *a , int n) {
#define prn(i) (((i) - 1) / 2)

    for (int i = 1, j, p; i < n; i++) {
        for (j = i; 0 < j; j = p) {
            p = prn(j);

            if (a[p] < a[j])
                swp(&a[p], &a[j]);
        }
    }
}

void hst(int *a, int n) {
    hpy(a, n);

    for (int i = n - 1; 0 <= i; i--) {
        swp(&a[0], &a[i]);

        hpy(a, i);
    }
}

#define srt 2

#if srt == 0
int kth(int *a, int n, int k) {
    qst(a, 0, n - 1);

    return a[k-1];
}
#elif srt == 1
int kth(int *a, int n, int k) {
    hst(a, n);

    return a[k-1];
}
#else
int kth(std::vector<int> &a, int k) {
    std::sort(a.begin(), a.end());

    return a[k-1];
}
#endif


int main() {
    int a[] = { 3, 2, 1, 4, 9 };

    // printf("%d", kth(a, sizeof(a) / sizeof(a[0]), 3));

    return 0;
}
