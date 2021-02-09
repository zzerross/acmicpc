#include <stdio.h>

#define DISTANCE 0x7fffffff
#define HEIGHT 100
#define WIDTH  100

int H, W, M[HEIGHT][WIDTH], D[HEIGHT][WIDTH];
int Y[] = { -1,  0,  1,  0 };
int X[] = {  0,  1,  0, -1 };

template <typename T>
void swap(T& i, T& j) {
    T t = i;
    i = j;
    j = t;
}

struct Vertex {
    int i = 0, j = 0;
    int g = 0;
    int d = DISTANCE;

    Vertex& set(int i, int j, int d) {
        this->d = d;

        return set(i, j);
    }

    Vertex& set(int i, int j) {
        this->i = i;
        this->j = j;

        return *this;
    }

    bool operator<(Vertex& o) {
        return d < o.d;
    }
} V[HEIGHT][WIDTH];

template <typename T, int S>
struct PriorityQueue {
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

        return *buf[l] < *buf[r] ? l : r;
    }

    bool empty() { return tail < 0; }

    T push(T d) {
        buf[++tail] = d;

        for (int p = prn(tail), c = tail; 0 < c; p = prn(c = p)) {
            if (*buf[p] < *buf[c])
                break;

            swap(buf[p], buf[c]);
        }

        return buf[tail];
    }

    T pop() {
        if (empty())
            return nullptr;

        T h = buf[0];
        buf[0] = buf[tail--];

        for (int p = 0, c = sch(p); p < tail && c <= tail; c = sch(p = c)) {
            if (*buf[p] < *buf[c])
                break;

            swap(buf[p], buf[c]);
        }

        return h;
    }
};

PriorityQueue<Vertex*, HEIGHT * WIDTH> Q;

bool range(int i, int j) {
    return 0 <= i && i < H && 0 <= j && j < W;
}

int main() {
    setbuf(stdout, NULL);

    scanf("%d %d", &W, &H);

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            scanf("%1d", &V[i][j].set(i, j).g);

    for (Vertex* u = Q.push(&V[0][0].set(0, 0, 0)); (u = Q.pop()) != nullptr;) {
        if (u->i == H - 1 && u->j == W - 1)
            break;

        for (int d = 0; d < 4; d++) {
            int y = u->i + Y[d];
            int x = u->j + X[d];

            if (!range(y, x))
                continue;

            Vertex* v = &V[y][x];

            if (u->d + v->g < v->d) {
                v->d = u->d + v->g;
                Q.push(v);
            }
        }
    }

    printf("%d\n", V[H-1][W-1].d);

    return 0;
}
