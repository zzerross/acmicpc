#include <stdio.h>
#include <stdlib.h>

#define CITIES 1001
#define BUSES  100000
#define WEIGHT 100000
#define DIST   (WEIGHT * CITIES)

template <typename T>
void swap(T& a, T& b) {
    T t = a;
    a = b;
    b = t;
}

struct Edge {
    int src, dst, weight;

    Edge& set(int s, int d, int w) {
        src = s;
        dst = d;
        weight = w;

        return *this;
    }
};

template <typename T>
struct Node {
    Node* next = nullptr;
    T data;
};

template <typename T, int S>
struct Array {
    T buf[S];
    int count = 0;

    T& alloc() {
        return buf[count++];
    }
};

Array<Node<Edge>, BUSES> gNodes;

template <typename T>
struct List {
    T* head = nullptr;
    int size = 0;

    void add(T* n) {
        n->next = head;
        head = n;
        size++;
    }
};

struct Vertex {
    Vertex* prev = nullptr;
    List<Node<Edge>> edges;
    int id;
    int dist = DIST;
    int count = 1;

    static bool prior(Vertex* u, Vertex* v) {
        return u->dist < v->dist;
    }
} gVertexes[CITIES];

template <typename T, int S, bool (*P) (T*, T*)>
struct PriorQ {
    T* buf[S];
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

    T* push(T* d) {
        buf[++tail] = d;

        for (int c = tail, p = prn(c); 0 < c; p = prn(c = p)) {
            if (P(buf[p], buf[c]))
                break;

            swap(buf[p], buf[c]);
        }

        return d;
    }

    T* pop() {
        if (tail < 0)
            return nullptr;

        T* t = buf[0];
        buf[0] = buf[tail--];

        for (int p = 0, c = pch(p); c <= tail; c = pch(p = c)) {
            if (P(buf[p], buf[c]))
                break;

            swap(buf[p], buf[c]);
        }

        return t;
    }
};

PriorQ<Vertex, BUSES, Vertex::prior> gQ;

int main() {
    for (int i = 0; i < CITIES; i++)
        gVertexes[i].id = i;

    int N, L, U, V;

    scanf("%d %d", &N, &L);

    for (int i = 0; i < L; i++) {
        Node<Edge>& n = gNodes.alloc();

        scanf("%d %d %d", &n.data.src, &n.data.dst, &n.data.weight);

        gVertexes[n.data.src].edges.add(&n);
    }

    scanf("%d %d", &U, &V);

    gVertexes[U].dist = 0;

    for (Vertex* u = gQ.push(&gVertexes[U]); u = gQ.pop();) {
        for (Node<Edge>* n = u->edges.head; n; n = n->next) {
            Edge& e = n->data;
            Vertex* v = &gVertexes[e.dst];
            int d = u->dist + e.weight;

            if (d < v->dist) {
                v->dist = d;
                v->count = u->count + 1;
                v->prev = u;

                gQ.push(v);
            }
        }
    }

    Vertex* v = &gVertexes[V];

    printf("%d\n%d\n", v->dist, v->count);

    int t[v->count] = { U }, c = v->count, i = v->count - 1;

    for (Vertex* u = &gVertexes[U]; v != u && 0 <= i; v = v->prev)
        t[i--] = v->id;

    for (i = 0; i < c; i++)
        printf("%d ", t[i]);

    printf("\n");

    return 0;
}
