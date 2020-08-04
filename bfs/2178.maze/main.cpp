#include <stdio.h>

#define S 100

int i, j, s, d, u, v, r = 0, I, J;
char M[S][S+1];

int dy[] = { 0,  0,  1, -1 };
int dx[] = { 1, -1,  0,  0 };

int rng(int i, int j) {
    return 0 <= i && i <= I && 0 <= j && j <= J;
}

struct qu {
    int f, r;
    int a[S*S*9];
    int b[S*S*9];
    int c[S*S*9];

    qu& init() {
        f = r = 0;

        return *this;
    }

    void push(int i, int j, int s) {
        a[r] = i;
        b[r] = j;
        c[r++] = s;
    }

    int pop(int& i, int& j, int& s) {
        if (f < r) {
            i = a[f];
            j = b[f];
            s = c[f++];

            return 1;
        }

        return 0;
    }
} qu;

int main() {
    scanf("%d %d", &I, &J);

    for (i = 0, --I, --J; i <= I; i++)
        scanf("%s", M[i]);

    for (qu.init().push(0, 0, 1); qu.pop(i, j, s) && (i != I || j != J);)
        for (d = 0; d < 4; d++)
            if (rng(u = i + dy[d], v = j + dx[d]))
                if (M[u][v] == '1')
                    qu.push(u, v, s + !!(M[u][v] = '0'));

    printf("%d\n", s);

    return 0;
}
