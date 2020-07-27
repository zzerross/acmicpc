#include <stdio.h>

int main() {
    double E[10] = { 1.0, 2.0, 2.5, };
    double F[10] = { 1.0, 1.0, 2.0, };

    for (int i = 3; i <= 9; i++)
        F[i] = F[i-1] * i;

    printf("n e\n");
    printf("- -----------\n");
    printf("0 1\n");
    printf("1 2\n");
    printf("2 2.5\n");

    for (int n = 3; n <= 9; n++) {
        E[n] = E[n-1] + (1.0 / F[n]);

        printf("%d %.09lf\n", n, E[n]);
    }
    
    return 0;
}
