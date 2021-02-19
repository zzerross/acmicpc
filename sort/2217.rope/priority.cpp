#include <stdio.h>

#ifdef use_pr
#define _pr(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define _ph(fmt, ...) _pr("%8s: " fmt, __func__, ##__VA_ARGS__)
#else
#define _pr(fmt, ...)
#define _ph(fmt, ...)
#endif

#define WEIGHT (10000 * 100000)
#define ROPES  100001

template <typename T>
void swap(T& a, T& b) {
    T t = a;
    a = b;
    b = t;
}

template <typename T>
int max(T i, T j) {
    return i < j ? j : i;
}

template <typename T>
bool prior(T i, T j) {
    return j < i;
}

template <typename T, int S, bool (*P) (T, T)>
struct PriorityQ {
    T buf[S];
    int tail = -1;

    int prn(int i) { return (i - 1) / 2; }
    int lch(int i) { return (i * 2) + 1; }
    int rch(int i) { return (i * 2) + 2; }
    int sch(int i) {
        int l = lch(i);
        int r = rch(i);

        if (tail < r)
            return l;

        return P(buf[l], buf[r]) ? l : r;
    }

    int size() {
        return tail + 1;
    }

    void push(T d) {
        buf[++tail] = d;

        for (int c = tail, p = prn(c); 0 < c; p = prn(c = p)) {
            if (P(buf[p], buf[c]))
                break;

            swap(buf[p], buf[c]);
        }
    }

    T pop() {
        T t = buf[0];
        buf[0] = buf[tail--];

        for (int p = 0, c = sch(p); c <= tail; c = sch(p = c)) {
            if (P(buf[p], buf[c]))
                break;

            swap(buf[p], buf[c]);
        }

        return t;
    }

    void dump(const char* s) {
#ifdef use_pr
        _pr("%8s: size=%d, ", s, size());

        for (int i = 0; i <= tail; i++)
            _pr("%d ", buf[i]);

        _pr("\n");
#endif
    }
};

PriorityQ<int, ROPES, prior> Q;

int main() {
    int N, h = 0;

    scanf("%d", &N);

    for (int a, i = 1; i <= N; i++, Q.push(a))
        scanf("%d", &a);

    for (int i = 1, s = Q.size(); i <= s; i++)
        h = max(h, i * Q.pop());

    printf("%d\n", h);

    return 0;
}
