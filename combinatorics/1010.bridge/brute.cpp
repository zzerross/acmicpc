#include <stdio.h>

int cmb(int i, int j) {
    if (i == j || i < 1)
        return 1;

    return cmb(i - 1, j - 1) + cmb(i, j - 1);
}

int main() {
    int T, i, j;

    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        scanf("%d %d", &i, &j);

        printf("%d\n", cmb(i, j));
    }

    return 0;
}
