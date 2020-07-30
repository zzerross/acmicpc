#include <stdio.h>

int main() {
    int n, i = 0, j, k = 0;

    scanf("%d", &n);

    while (i++ < 5) {
        scanf("%d", &j);

        if (j % 10 == n)
            k++;
    }

    printf("%d\n", k);

    return 0;
}
