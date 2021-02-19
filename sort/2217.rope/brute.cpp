#include <stdio.h>

#define H (100000 * 10000)

int main() {
    int N, h = 0;

    scanf("%d", &N);

    for (int i, l = H, n = 1; n <= N; n++) {
        scanf("%d", &i);

        if (i < l)
            l = i;

        if (h < l * n)
            h = l * n;

        if (h < i)
            h = i;

        // printf("i=%d l=%d h=%d\n", i, l, h);
    }

    printf("%d\n", h);

    return 0;
}
