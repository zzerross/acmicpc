#include <stdio.h>

int main() {
    int n, a, b;

    for (scanf("%d", &n); n--;) {
        scanf("%d,%d", &a, &b);

        printf("%d\n", a + b);
    }

    return 0;
}
