#include <stdio.h>

int main() {
    int T, N;

    for (scanf("%d", &T); T--;) {
        scanf("%d", &N);

        for (int i = 0; 0 < N; i++, N /= 2)
            if (N % 2)
                printf("%d ", i);

        printf("\n");
    }

    return 0;
}
