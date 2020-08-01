#include <stdio.h>

int main() {
    int n, i = 0, j, c = 0;

    for (scanf("%d", &n); i < n; scanf("%d", &j), c += j, i++);

    printf("Junhee is%s cute!\n", n / 2 < c ? "" : " not");

    return 0;
}
