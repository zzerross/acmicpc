#include <stdio.h>

template <size_t S>
struct Integer {
    char buf[S+1];
    int ary[S+2] = { 0, };
    size_t tail = 0;

    Integer(size_t t = 0): tail(t) {
    }

    Integer& read() {
        scanf("%s", buf);

        for (tail = 0; buf[tail]; tail++)
            ary[tail+1] = buf[tail] - '0';

        return *this;
    }

    Integer operator+(Integer& o) {
        Integer& u = tail < o.tail ? o : *this;
        Integer& v = tail < o.tail ? *this : o;
        Integer<S> r(u.tail);

        for (int i = u.tail, j = v.tail; 0 <= i; i--, j--) {
            r.ary[i] += u.ary[i] + v.ary[j];

            if (10 <= r.ary[i]) {
                r.ary[i] -= 10;
                r.ary[i-1]++;
            }
        }

        return r;
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

    (c = a.read() + b.read()).dump("\n");

    return 0;
}
