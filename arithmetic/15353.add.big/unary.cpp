#include <stdio.h>

template <size_t S>
struct Integer {
    char buf[S+1];
    int ary[S+2] = { 0, };
    size_t tail = 0;

    Integer& read() {
        scanf("%s", buf);

        for (tail = 0; buf[tail]; tail++)
            ary[tail+1] = buf[tail] - '0';

        return *this;
    }

    Integer& operator+=(Integer& o) {
        for (int i = tail, j = o.tail; 0 <= i; i--, j--) {
            ary[i] += o.ary[j];

            if (10 <= ary[i]) {
                ary[i] -= 10;
                ary[i-1]++;
            }
        }

        return *this;
    }

    void dump(const char* e) {
        for (size_t i = 0; i <= tail; i++)
            if (i || ary[i])
                printf("%d", ary[i]);

        printf("%s", e);
    }
};

int main() {
    Integer<100000> a, b, c;

    (a.read().tail < b.read().tail ? b += a : a += b).dump("\n");

    return 0;
}
