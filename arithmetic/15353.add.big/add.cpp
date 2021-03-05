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

    Integer& add(Integer& a, Integer& b) {
        Integer& u = a.tail < b.tail ? b : a;
        Integer& v = a.tail < b.tail ? a : b;

        tail = u.tail;

        for (int i = u.tail, j = v.tail; 0 <= i; i--, j--) {
            ary[i] += u.ary[i] + v.ary[j];

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

    c.add(a.read(), b.read()).dump("\n");

    return 0;
}
