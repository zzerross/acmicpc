#include <stdio.h>

int main() {
    int N;
    char S[51];

    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        scanf("%s", S);

        printf("String #%d\n", i);

        for (int i = 0; S[i]; i++)
            printf("%c", S[i] == 'Z' ? 'A' : S[i] + 1);

        printf("\n\n");
    }

    return 0;
}
