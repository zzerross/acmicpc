#include <stdio.h>

int main() {
    for (int i, j, k;;) {
        scanf("%d %d %d", &i, &j, &k);

        if (!i)
            break;

        i *= i;
        j *= j;
        k *= k;

        printf("%s\n", 
                i + j == k ? "right" :
                i + k == j ? "right" :
                j + k == i ? "right" : "wrong");
    }

    return 0;
}
