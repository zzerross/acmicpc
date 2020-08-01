#include <stdio.h>

int main() {
    int t = 28, i, a = 0;

    while (t--) {
        scanf("%d", &i);

        a |= (1 << --i);
    }

    for (i = 0; i < 30; i++)
        if (!(a & (1 << i)))
            printf("%d\n", i + 1);


    return 0;
}
