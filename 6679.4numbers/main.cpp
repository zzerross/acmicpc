#include <stdio.h>

int sum(int n, int b) {
    int s = 0;

    for (; 0 < n; n /= b)
        s += (n % b);

    return s;
}

int main() {
    for (int a, b, n = 1000; n < 10000; n++) {
        a = sum(n, 10);
        b = sum(n, 12);

        if (a == b)
            if (a == sum(n, 16))
                printf("%d\n", n);
    }

    return 0;
}
