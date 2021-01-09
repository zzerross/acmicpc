#include <stdio.h>

#define S 100001

int N, K;

struct pt {
    int t, i;
};

struct qu {
    static const int s = S;
    struct pt b[s];

    int f, r, n;
    int l, h;
    bool v[S];

    void init(int i, int l, int h) {
        f = r = n = 0;

        this->l = l;
        this->h = h;

        push(0, i);
    }

    int range(int i) {
        return l <= i && i < h;
    }

    void push(int t, int i) {
        if (s <= n) {
            printf("overflow s=%d n=%d\n", s, n);
            return;
        }

        if (!range(i) || v[i])
            return;

        v[i] = true;

        n++;

        b[r].t = t;
        b[r].i = i;

        if (s <= ++r)
            r = 0;
    }

    int pop(struct pt& p) {
        p = b[f];

        if (s <= ++f)
            f = 0;

        n--;

        return p.i;
    }
} q = {
    .v = { 0, },
};

int main() {
    scanf("%d %d", &N, &K);

    struct pt n;

    for (q.init(N, 0, S); q.pop(n) != K;) {
        q.push(n.t + 1, n.i + 1);
        q.push(n.t + 1, n.i - 1);
        q.push(n.t + 1, n.i * 2);
    }

    printf("%d\n", n.t);

    return 0;
}
