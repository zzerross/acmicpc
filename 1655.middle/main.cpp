/**
 * @ref https://www.acmicpc.net/problem/1655
 */

#include <stdio.h>

template <typename T, int S>
struct pq {
    T buf[S];
    int size;
    bool min;

    pq(bool m): size(0), min(m) {
    }

    //    0
    //  1   2
    // 3 4 5 6
    inline int prn(int i) { return (i - 1) / 2; }
    inline int lch(int i) { return i * 2 + 1; }
    inline int rch(int i) { return i * 2 + 2; }
    inline int mch(int i) {
        int l = lch(i), r = rch(i);

        if (r < size)
            return prior(l, r) ? l : r;

        return l;
    }

    inline bool nil() { return size <= 0; }

    inline bool prior(int i, int j) {
        return min ? buf[i] <= buf[j] : buf[i] >= buf[j];
    }

    inline void swap(T& a, T& b) {
        T t = a;

        a = b;
        b = t;
    }

    void push(const T& d) {
        buf[size] = d;

        for (int i = size++, p = prn(i); 0 <= p; i = p, p = prn(i)) {
            if (prior(p, i))
                break;

            swap(buf[p], buf[i]);
        }
    }

    T pop() {
        T t = buf[0];

        buf[0] = buf[--size];

        for (int i = 0, c = mch(i); c < size; i = c, c = mch(i)) {
            if (prior(i, c))
                break;

            swap(buf[i], buf[c]);
        }

        return t;
    }

    inline T top() { return buf[0]; }

    void dump(const char* s = nullptr) {
        printf("%5s: ", s ? s : "pq");

        for (int i = 0; i < size; i++)
            printf("%+6d ", buf[i]);

        printf("\n");
    }
};

int main() {
#define S 100000

    pq<int, S> l(false);
    pq<int, S> h(true);

    int N;

    scanf("%d", &N);

    for (int d, i = 0; i < N; i++) {
        scanf("%d", &d);

        if (l.size == h.size)
            l.push(d);
        else
            h.push(d);

        if (!h.nil() && l.top() > h.top()) {
            int a = l.pop();
            int b = h.pop();

            l.push(b);
            h.push(a);
        }

        printf("%d\n", l.top());
    }

    return 0;
}
