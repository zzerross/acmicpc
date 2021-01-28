#include <stdio.h>

int max(int i, int j) {
    return i < j ? j : i;
}

int main() {
    int r = 0;

    for (int u, v, s = 0, i = 0 ; i < 4; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d %d", &u, &v);

            r = max(r, s -= u);
            r = max(r, s += v);
        }
    }

    printf("%d\n", r);

    return 0;
}
