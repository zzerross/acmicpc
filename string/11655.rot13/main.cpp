/**
 * https://www.acmicpc.net/problem/11655
 */
#include <stdio.h>

#define Z 101

#define A(c) ('A' + ((c) - 'A' + 13) % ('Z' - 'A' + 1))
#define a(c) ('a' + ((c) - 'a' + 13) % ('z' - 'a' + 1))

int main() {
    for (char c; (c = getchar()) != EOF;) {
        if ('A' <= c && c <= 'Z')
            c = A(c);
        else if ('a' <= c && c <= 'z')
            c = a(c);

        printf("%c", c);
    }

    return 0;
}
