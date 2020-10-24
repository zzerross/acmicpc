#include <stdio.h>

#define Z 1000
#define Q (Z * Z)

int W, H, A[Z][Z];
int Y[] = { 1, -1,  0, 0 };
int X[] = { 0,  0, -1, 1 };

int max(int i, int j) {
    return i > j ? i : j;
}

int range(int i, int j) {
    return 0 <= i && i < H && 0 <= j && j < W;
}

template <typename T>
void swap(T& a, T& b) {
    T t = a;

    a = b;
    b = t;
}

struct Point {
    int y, x, d;

    bool operator<(Point& o) {
        return d < o.d;
    }
};

struct PriorityQueue {
    Point b[Q];
    int n;

    PriorityQueue (): n(0) { }

    int prn(int i) { return (i - 1) / 2; }
    int lch(int i) { return (i * 2) + 1; }
    int rch(int i) { return (i * 2) + 2; }
    int mch(int i) {
        int l = lch(i);
        int r = rch(i);

        if (n <= r)
            return l;

        return b[l].d < b[r].d ? l : r;
    }

    void push(int i, int j, int v) {
        Point& t = b[n++];

        t.y = i;
        t.x = j;
        t.d = v;

        for (int c = n - 1, p = prn(c); 0 <= p && b[c] < b[p]; c = p, p = prn(c))
            swap<Point>(b[p], b[c]);
    }

    bool pop(Point& t) {
        if (n < 1)
            return false;

        t = b[0];
        b[0] = b[--n];

        for (int p = 0, c = mch(p); c < n && b[c] < b[p]; p = c, c = mch(c))
            swap<Point>(b[p], b[c]);

        return true;
    }
} qu;

int main() {
    scanf("%d %d", &W, &H);

    int r = 1, nr = 0;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            scanf("%d", &A[i][j]);

            if (A[i][j] == 1)
                qu.push(i, j, A[i][j]);
            else if (A[i][j] == 0)
                nr++;
        }
    }

    for (Point t; qu.pop(t);) {
        for (int k = 0; k < 4; k++) {
            int y = t.y + Y[k];
            int x = t.x + X[k];

            if (!range(y, x))
                continue;

            if (!A[y][x]) {
                nr--;

                r = max(r, A[y][x] = t.d + 1);

                qu.push(y, x, A[y][x]);
            }
        }
    }

    printf("%d\n", 0 < nr ? -1 : r - 1);

    return 0;
}
