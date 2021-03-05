#include <stdio.h>
#include <assert.h>

#ifdef use_pr
#define _pr(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define _ph(fmt, ...) _pr("%8s: " fmt, __func__, ##__VA_ARGS__)
#else
#define _pr(fmt, ...)
#define _ph(fmt, ...)
#endif

#define POINTS (100000 + 2)

template <typename T>
void swap(T& a, T& b) {
    T t = a;
    a = b;
    b = t;
}

struct Point {
    int t;
    int x;

    Point& set(int t, int x) {
        this->t = t;
        this->x = x;

        return *this;
    }

    static bool prior(Point* a, Point* b) {
        return a->t == b->t ? a->x < b->x : a->t < b->t;
    }

    int id() {
        return x;
    }

    void dump() {
#ifdef use_pr
        _pr("(%d, %3d) ", t, x); 
#endif
    }
};

template <typename T, size_t S>
struct Array {
    T buf[S];
    size_t size = 0;

    T& alloc() {
        assert(size < S);

        return buf[size++];
    }
};

Array<Point, POINTS> gPoints;

template <typename T, size_t S, bool (*P)(T, T)>
struct PriorityQ {
    T buf[S];
    bool pushed[S] = { false, };
    int tail = -1;

    int prn(int i) { return (i - 1) / 2; }
    int lch(int i) { return (i * 2) + 1; }
    int rch(int i) { return (i * 2) + 2; }
    int pch(int i) {
        int l = lch(i);
        int r = rch(i);

        if (tail < r)
            return l;

        return P(buf[l], buf[r]) ? l : r;
    }

    T push(T d) {
        if (pushed[d->x])
            return nullptr;

        pushed[d->x] = true;

        buf[++tail] = d;

        for (int c = tail, p = prn(c); 0 < c; p = prn(c = p)) {
            if (P(buf[p], buf[c]))
                break;

            swap(buf[p], buf[c]);
        }

        dump(__func__);

        return d;
    }

    T pop() {
        if (tail < 0)
            return nullptr;

        T t = buf[0];
        buf[0] = buf[tail--];

        for (int p = 0, c = pch(p); c <= tail; c = pch(p = c)) {
            if (P(buf[p], buf[c]))
                break;

            swap(buf[p], buf[c]);
        }

        dump(__func__);

        return t;
    }

    bool pushable(int i) {
        return !pushed[i];
    }

    void dump(const char* s) {
#ifdef use_pr
        _pr("%8s: size=%2d, ", s, tail + 1);

        for (int i = 0; i <= tail; i++)
            buf[i]->dump();

        _pr("\n");
#endif
    }
};

PriorityQ<Point*, POINTS, Point::prior> gQ;

int gVisited[POINTS] = { 0, };

int visitable(int i) {
    return 0 <= i && i < POINTS && gQ.pushable(i);
}

int main() {
    setbuf(stdout, NULL);

    int N, K;

    scanf("%d %d", &N, &K);

    Point* p = gQ.push(&gPoints.alloc().set(0, N));

    for (int x; (p = gQ.pop());) {
        if (p->x == K)
            break;

        if (visitable(x = p->x * 2))
            gQ.push(&gPoints.alloc().set(p->t + 0, x));

        if (visitable(x = p->x + 1))
            gQ.push(&gPoints.alloc().set(p->t + 1, x));

        if (visitable(x = p->x - 1))
            gQ.push(&gPoints.alloc().set(p->t + 1, x));
    }

    printf("%d\n", p ? p->t : -1);

    return 0;
}
