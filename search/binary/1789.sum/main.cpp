/**
 * https://www.acmicpc.net/problem/1789
 */
#include <stdio.h>

int main() {
    unsigned long long S, s = 0, i = 0;

    scanf("%llu", &S);

    while ((s += ++i) <= S);

    printf("%llu\n", i - 1);

    return 0;
}
