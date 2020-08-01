#include <stdio.h>

int main() {
    char S[5][16] = { 0, };

    for (int i = 0; i < 5; i++)
        scanf("%s", S[i]);

    for (int i = 0; i < 16; i++)
        for (int j = 0; j < 5; j++)
            if (S[j][i])
                printf("%c", S[j][i]);

    return 0;
}
