#include <stdio.h>

int main() {
    int i = 0, j, k;

    scanf("%d", &j);

    for (i = 1; i <= 9; i++, j -= k)
        scanf("%d", &k);

    printf("%d\n", j);

    return 0;
}
