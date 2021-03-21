#include <stdio.h>

#define WIDTH 50
#define NODES (WIDTH * WIDTH)
#define DIST  (WIDTH * WIDTH)

char M[WIDTH][WIDTH+1];
int W, D[WIDTH][WIDTH];
int Y[] = { -1,  1,  0,  0 };
int X[] = {  0,  0, -1,  1 };

template <typename T>
void swap(T& a, T& b) {
    T t = a;
    a = b;
    b = t;
}

bool valid(int y, int x) {
    return 0 <= y && y < W && 0 <= x && x < W;
}

struct Node {
    int y, x;

    bool operator<(Node& o) {
        return D[y][x] < D[o.y][o.x];
    }
};

template <typename T, int S>
struct PrioQ {
    T buf[S];
    int tail = -1;

    int prn(int i) { return (i - 1) / 2; }
    int lch(int i) { return (i * 2) + 1; }
    int rch(int i) { return (i * 2) + 2; }
    int pch(int i) {
        int l = lch(i);
        int r = rch(i);

        if (tail < r)
            return l;

        return buf[l] < buf[r] ? l : r;
    }

    bool empty() {
        return tail < 0;
    }

    void push(T d) {
        buf[++tail] = d;

        for (int c = tail, p = prn(c); 0 < c; p = prn(c = p)) {
            if (buf[p] < buf[c])
                break;

            swap(buf[p], buf[c]);
        }
    }

    T pop() {
        T t = buf[0];
        buf[0] = buf[tail--];

        for (int p = 0, c = pch(p); c <= tail; c = pch(p = c)) {
            if (buf[p] < buf[c])
                break;

            swap(buf[p], buf[c]);
        }

        return t;
    }
};

struct PrioQ<Node, NODES> Q;

int main() {
    scanf("%d", &W);

    for (int i = 0; i < W; i++) {
        scanf("%s", M[i]);

        for (int j = 0; j < W; j++)
            D[i][j] = DIST;
    }

    D[0][0] = (M[0][0] == '0');

    for (Q.push({0, 0}); !Q.empty();) {
        Node n = Q.pop();

        for (int i = 0; i < 4; i++) {
            int y = n.y + Y[i];
            int x = n.x + X[i];

            if (valid(y, x)) {
                int d = D[n.y][n.x] + (M[y][x] == '0');
                if (d < D[y][x]) {
                    D[y][x] = d;
                    Q.push({y, x});
                }
            }
        }
    }

    printf("%d\n", D[W-1][W-1]);

    return 0;
}
