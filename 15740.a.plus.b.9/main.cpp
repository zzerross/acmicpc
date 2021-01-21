#include <stdio.h>

#define S 10002

#define I(c) ((c) - '0')
#define C(i) ((i) + '0')

int main() {
    char A[S], B[S];

    scanf("%s %s", A, B);

    int a = A[0] == '-' ? -1 : 1;
    int b = B[0] == '-' ? -1 : 1;

    for (n = 0; A[n++];);
    for (m = 0; B[m++];);

    int k = 0, c = 0, i = n - 1, j = m - 1, s;

    for (; 0 <= i && 0 <= j; i--, j--, c = s % 10) {
        s = c + (a * I(A[i])) + (b * I(B[j]));

        R[k++] = C(s / 10);
    }

    R[k++] = C(c);
    R[k++] = '\0';

    for (i = 0; i < k; i++)
        printf("%c", 

    return 0;
}
