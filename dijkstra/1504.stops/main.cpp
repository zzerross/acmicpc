#include <stdio.h>

#define VERTEXES 801
#define EDGES    (200000 * 2)
#define WEIGHT   1000
#define DIST     (VERTEXES * WEIGHT)

int min(int i, int j) {
    return i < j ? i : j;
}

int N, E, A, B;

struct Vertex;

struct Edge {
    Vertex* v = nullptr;
    int w = 0;
};

template <typename T>
struct Node {
    T data;
    Node* next;
};

template <typename T, int S>
struct Array {
    T buf[S];
    int size = 0;

    T& alloc() {
        return buf[size++];
    }
};

Array<Node<Edge>, EDGES> gNodes;

template <typename T>
struct List {
    Node<T>* head = nullptr;
    int size = 0;

    void add(Node<T>* n) {
        if (head)
            n->next = head;

        head = n;

        size++;
    }
};

struct Vertex {
    int d;
    List<Edge> edges;

    Vertex& set(int d) {
        this->d = d;

        return *this;
    }

    static bool shortter(Vertex* a, Vertex* b) {
        return a->d < b->d;
    }
} G[VERTEXES];

template <typename T>
void swap(T& a, T& b) {
    T t = a;
    a = b;
    b = t;
}

template <typename T, int S, bool (*C) (T, T)>
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

        return C(buf[l], buf[r]) ? l : r;
    }

    bool empty() {
        return tail < 0;
    }

    void init(T d) {
        tail = -1;

        push(d);
    }

    void push(T d) {
        buf[++tail] = d;

        for (int c = tail, p = prn(c); 0 < c; p = prn(c = p)) {
            if (C(buf[p], buf[c]))
                break;

            swap(buf[p], buf[c]);
        }
    }

    T pop() {
        T t = buf[0];
        buf[0] = buf[tail--];

        for (int p = 0, c = sch(p); c < tail; c = sch(p = c)) {
            if (C(buf[p], buf[c]))
                break;

            swap(buf[p], buf[c]);
        }

        return t;
    }
};

PriorityQ<Vertex*, EDGES, Vertex::shortter> Q;

int djk(Vertex* s, Vertex* d) {
    for (int i = 1; i <= N; i++)
        G[i].d = DIST;

    Q.init(&s->set(0));

    while (!Q.empty()) {
        Vertex* u = Q.pop();

        if (u == d)
            break;

        Node<Edge>* n = u->edges.head;

        for (int j = 0; j < u->edges.size; j++, n = n->next) {
            Edge& e = n->data;
            Vertex* v = e.v;

            if (u->d + e.w < v->d) {
                v->d = u->d + e.w;

                Q.push(v);
            }
        }
    }

    return d->d;
}

int djk(int s, int d) {
    return djk(&G[s], &G[d]);
}

int djk(int a, int b, int c, int d) {
    int s = 0, r;

    if ((r = djk(a, b)) == DIST)
        return DIST;

    s += r;

    if ((r = djk(b, c)) == DIST)
        return DIST;

    s += r;

    if ((r = djk(c, d)) == DIST)
        return DIST;

    return s += r;
}

int main() {
    scanf("%d %d", &N, &E);

    for (int i, j, w, e = 0; e < E; e++) {
        scanf("%d %d %d", &i, &j, &w);

        for (int k = 0; k < 2; k++, swap(i, j)) {
            Node<Edge>& n = gNodes.alloc();
            Edge& e = n.data;

            e.v = &G[j];
            e.w = w;

            G[i].edges.add(&n);
        }
    }

    scanf("%d %d", &A, &B);

    int r = min(djk(1, A, B, N), djk(1, B, A, N));

    printf("%d\n", r < DIST ? r : -1);

    return 0;
}
