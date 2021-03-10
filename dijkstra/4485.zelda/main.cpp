#include <stdio.h>
#include <assert.h>

#define WIDTH 125
#define NODES (WIDTH * WIDTH * 100)
#define DISTANCE (9 * NODES)

int gDst[WIDTH][WIDTH];
int gMap[WIDTH][WIDTH], N;
int Y[] = { -1, 0, 1,  0 };
int X[] = {  0, 1, 0, -1 };

bool valid(int i, int j) {
    return 0 <= i && i < N && 0 <= j && j < N;
}

template <typename T>
void swap(T& a, T& b) {
    T t = a;
    a = b;
    b = t;
}

struct Node {
    int i, j;

    Node& set(int i, int j) {
        this->i = i;
        this->j = j;

        return *this;
    }
};

static bool prior(Node* a, Node* b) {
    return gDst[a->i][a->j] < gDst[b->i][b->j];
}


template <typename T, int S>
struct Pool {
    T buf[S];
    bool allocated[S];

    void init() {
        for (int i = 0; i < S; i++)
            allocated[i] = false;
    }

    T& alloc() {
        for (int i = 0; i < S; i++) {
            if (!allocated[i]) {
                allocated[i] = true;
                return buf[i];
            }
        }

        assert(false);
    }

    void free(T* n) {
        int i = index(n);
        
        if (0 <= i)
            allocated[i] = false;
    }

    int index(T* n) {
        return n - buf;
    }

    bool isAllocated(T* n) {
        int i = index(n);

        return i < 0 ? false : allocated[i];
    }
};

template <typename T, int S, bool (*P) (T, T)>
struct PriorityQ {
    T buf[S];
    int tail;

    T init(T d) {
        tail = -1;

        return push(d);
    }

    int prn(int i) { return (i - 1) / 2; }
    int lch(int i) { return (i * 2) + 1; }
    int rch(int i) { return (i * 2) + 2; }
    int sch(int i) {
        int l = lch(i);
        int r = rch(i);

        if (tail <= r)
            return l;

        return P(buf[l], buf[r]) ? l : r;
    }

    T push(T d) {
        buf[++tail] = d;

        for (int c = tail, p = prn(c); 0 < c; p = prn(c = p))
            if (!P(buf[p], buf[c]))
                swap(buf[p], buf[c]);

        return d;
    }

    T pop() {
        if (tail < 0)
            return nullptr;

        T t = buf[0];
        buf[0] = buf[tail--];

        for (int p = 0, c = sch(p); c <= tail; c = sch(p = c))
            if (!P(buf[p], buf[c]))
                swap(buf[p], buf[c]);

        return t;
    }
};

Pool<Node, NODES> gNodes;
PriorityQ<Node*, NODES, prior> gQ;

int main() {
    for (int t = 1;; t++) {
        scanf("%d", &N);

        if (!N)
            break;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                gDst[i][j] = DISTANCE;

                scanf("%d", &gMap[i][j]);
            }
        }

        gNodes.init();

        gDst[0][0] = gMap[0][0];

        for (Node* n = gQ.init(&gNodes.alloc().set(0, 0)); (n = gQ.pop()); gNodes.free(n)) {
            if (n->i == N - 1 && n->j == N - 1)
                break;

            for (int k = 0; k < 4; k++) {
                int i = n->i + Y[k];
                int j = n->j + X[k];

                if (valid(i, j)) {
                    int d = gDst[n->i][n->j] + gMap[i][j];
                    if (d < gDst[i][j]) {
                        gDst[i][j] = d;
                        gQ.push(&gNodes.alloc().set(i, j));
                    }
                }
            }
        }

        printf("Problem %d: %d\n", t, gDst[N-1][N-1]);
    }

    return 0;
}
