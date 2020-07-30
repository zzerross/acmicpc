#include <stdio.h>

int main() {
    int n = 0, r, i, a[] = { 500, 100, 50, 10, 5, 1 };

    scanf("%d", &r);

    for (r = 1000 - r, i = 0; r; n += r / a[i], r %= a[i++]);

    printf("%d\n", n);

    return 0;
}
