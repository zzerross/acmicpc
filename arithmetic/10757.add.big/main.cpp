#include <stdio.h>

template <int S>
struct Integer {
    int a[S];
    char b[S];
    size_t s;

    size_t read() {
        scanf("%s", b);

        for (a[0] = s = 0; b[s]; s++)
            a[s+1] = b[s] - '0';

        return s;
    }

    Integer& operator+=(Integer& o) {
        for (int i = s, j = o.s; 0 < i || 0 < j; i--, j = j ? j - 1 : 0) {
            if (10 <= (a[i] = a[i] + o.a[j])) {
                a[i] -= 10;
                a[i-1] += 1;
            }
        }

        return *this;
    }

    void print() {
        for (size_t i = 0; i <= s; i++)
            if (i || a[i])
                printf("%d", a[i]);
    }
};

int main() {
    Integer<10001> a, b;

    if (a.read() < b.read())
        (b += a).print();
    else
        (a += b).print();

    printf("\n");

    return 0;
}
