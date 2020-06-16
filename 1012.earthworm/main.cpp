#include <stdio.h>

#define S 50
#define Z 2500

int T, N, M, K, A[S][S];

int dy[] = { 0, 0,  1, -1 };
int dx[] = { 1, -1, 0, 0, };

struct Points {
    int y[Z];
    int x[Z];
    int f;
    int r;

    Points& init() {
        f = 0;
        r = 0;

        return *this;
    }

    bool nil() {
        return f == r;
    }

    void push(int i, int j) {
        y[r] = i;
        x[r++] = j;
    }

    void pop(int& i, int& j) {
        i = y[f];
        j = x[f++];
    }
} q;

bool rng(int i, int j) {
    return 0 <= i && i < N && 0 <= j && j < M;
}

int main() {
    for (scanf("%d", &T); T--;) {
        scanf("%d %d %d", &N, &M, &K);

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                A[i][j] = 0;

        for (int i, j, k = 0; k < K; k++) {
            scanf("%d %d", &i, &j);

            A[i][j] = 1;
        }

        int r = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!A[i][j])
                    continue;

                r++;

                q.init().push(i, j);
                A[i][j] = 0;

                for (int y, x; !q.nil();) {
                    q.pop(y, x);

                    for (int d = 0; d < 4; d++) {
                        int u = y + dy[d];
                        int v = x + dx[d];

                        if (!rng(u, v) || !A[u][v])
                            continue;

                        q.push(u, v);
                        A[u][v] = 0;
                    }
                }
            }
        }

        printf("%d\n", r);
    }

    return 0;
}
