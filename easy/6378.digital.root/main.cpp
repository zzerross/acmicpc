#include <stdio.h>

struct Num {
    char b[1001];

    inline void init() {
        b[0] = '0';
        b[1] = 0;
    }

    inline int I(char c) {
        return c == 0 ? 0 : c - '0';
    }

    inline char C(int i) {
        return i + '0';
    }

    void add(char c) {
        int u, i;

        for (u = I(c), i = 0; 0 < u; i++, u /= 10) {
            u = u + I(b[i]);

            if (!b[i])
                b[i+1] = b[i];

            b[i] = C(u % 10);
        }
    }

    bool zero() {
        return b[0] == '0';
    }

    bool root() {
        return b[1] == 0;
    }
};

int main() {
    Num N[2];
    Num *a = &N[0];
    Num *b = &N[1];
    Num *t;

    for (;;) {
        scanf("%s", a->b);

        if (a->zero())
            break;

        for (;; t = a, a = b, b = t) {
            b->init();

            for (int i = 0; a->b[i]; i++)
                b->add(a->b[i]);

            if (b->root())
                break;
        }

        printf("%s\n", b->b);
    }

    return 0;
}
