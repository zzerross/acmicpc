#include <stdio.h>

int main() {
    for (int r, k, j, i = 0; i < 3; i++) {
        for (r = j = 0; j < 4; j++, r += k)
            scanf("%d", &k);

        printf("%c\n", 0 < r ? 1 < r ? 2 < r ? 3 < r ? 'E' : 'A' : 'B' : 'C' : 'D');
    }

    return 0;
}
