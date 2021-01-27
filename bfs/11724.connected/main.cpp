#include <stdio.h>

#define NODES 1001
#define LINKS ((NODES * (NODES - 1) / 2) * 2)

int N, M, R = 0, V[NODES] = { 0, };

template <typename T>
struct Node {
    T data;
    Node* next;

    Node& init(T data) {
        this->data = data;
        this->next = nullptr;

        return *this;
    }
};

template <typename T, int S>
struct Array {
    T buf[S];
    size_t len = 0;

    T& alloc() {
        return buf[len++];
    }
};

template <typename T>
struct List {
    T* head = nullptr;
    size_t len = 0;

    void add(T* node) {
        if (head)
            node->next = head;
        
        head = node;

        len++;
    }
};

struct Array<Node<int>, LINKS> gNodes;
struct List<Node<int>> gList[NODES];

int dfs(int u) {
    if (V[u])
        return 0;

    V[u] = 1;

    Node<int>* node = gList[u].head;

    for (size_t i = 0; i < gList[u].len; i++, node = node->next)
        if (node)
            dfs(node->data);

    return 1;
}

int main() {
    // printf("%.3lfmb\n", sizeof(gNodes) / (1024.0 * 1024.0));

    scanf("%d %d", &N, &M);

    for (int u, v, i = 0; i < M; i++) {
        scanf("%d %d", &u, &v);

        gList[u].add(&gNodes.alloc().init(v));
        gList[v].add(&gNodes.alloc().init(u));
    }

    for (int u = 1; u <= N; u++)
        if (dfs(u))
            R++;

    printf("%d\n", R);

    return 0;
}
