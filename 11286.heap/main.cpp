/**
 * @ref https://www.acmicpc.net/problem/11286
 */
#include <stdio.h>

#define S 100000

int T, N;

static void swap(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

static int abs(int i) {
    return i < 0 ? -i : i;
}

static int small(int a, int b) {
    return abs(a) == abs(b) ? a <= b : abs(a) <= abs(b);
}

struct pq {
    int buf[S];
    int size;

    pq(): size(0) { }

    //    0
    //  1   2
    // 3 4 5 6
    inline int prn(int i) { return --i / 2; }
    inline int lch(int i) { return i * 2 + 1; }
    inline int rch(int i) { return i * 2 + 2; }
    inline int mch(int i) {
        int l = lch(i), r = rch(i);

        if (r < size)
            return small(buf[l], buf[r]) ? l : r;

        return l;
    }

    void push(int d) {
        buf[size++] = d;

        for (int i = size-1, p = prn(i); 0 < i; i = p, p = prn(i)) {
            if (small(buf[p], buf[i]))
                break;

            swap(buf[p], buf[i]);
        }
    }

    int pop() {
        if (size < 1)
            return 0;

        int t = buf[0];

        buf[0] = buf[--size];

        for (int i = 0, c = mch(i); c < size; i = c, c = mch(i)) {
            if (small(buf[i], buf[c]))
                break;

            swap(buf[i], buf[c]);
        }

        return t;
    }
} pq;

int main() {
    for (scanf("%d", &T); T--;) {
        scanf("%d", &N);

        if (N) {
            pq.push(N);
        } else {
            printf("%d\n", pq.pop());
        }
    }

    return 0;
}
