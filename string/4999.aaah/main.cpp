#include <stdio.h>

#define S 1000

size_t strlen(char* a) {
    size_t n = 0;

    while (a[n++]);

    return n;
}

int main() {
    char A[S], B[S];

    scanf("%s %s", A, B);

    printf("%s\n", strlen(A) < strlen(B) ? "no" : "go");

    return 0;
}
