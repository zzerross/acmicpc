#include <stdio.h>

#define NODES 10001
#define RELATIONS (100000 * 2)

int N, M;
bool V[NODES];

struct Node {
    int id;
    int weight;
    Node* next;

    Node& init(int i, int w) {
        id = i;
        weight = w;
        next = nullptr;

        return *this;
    }
};

template <typename T, int S>
struct Array {
    int size;
    T buf[S];

    T& alloc() {
        return buf[size++];
    }
};

Array<Node, RELATIONS> A = { .size = 0, };

struct List {
    size_t size;
    Node* head;

    void add(int i, int w) {
        Node& n = A.alloc().init(i, w);
        Node* p = head;

        head = &n;

        if (p)
            head->next = p;

        size++;
    }
} L[NODES];

int max(int i, int j) {
    return i < j ? j : i;
}

bool dfs(int i, int e, int w) {
    if (V[i])
        return false;

    V[i] = true;

    if (i == e)
        return true;

    List& l = L[i];
    Node* n = l.head;

    for (size_t j = 0; j < l.size; j++, n = n->next)
        if (w <= n->weight)
            if (dfs(n->id, e, w))
                return true;

    return false;
}

int main() {
    scanf("%d %d", &N, &M);

    int s, e, l = 0, h = 0;

    for (int a, b, w, i = 0; i < M; i++, h = max(h, w)) {
        scanf("%d %d %d", &a, &b, &w);

        L[a].add(b, w);
        L[b].add(a, w);
    }

    scanf("%d %d", &s, &e);

    while (l <= h) {
        for (int i = 0; i <= N; i++)
            V[i] = false;

        int m = (l + h) / 2;
        if (dfs(s, e, m))
            l = m + 1;
        else
            h = m - 1;
    }

    printf("%d\n", h);

    return 0;
}
