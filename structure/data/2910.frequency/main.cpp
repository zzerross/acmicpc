#include <cstdio>

#define Z 1000
#define H 16000000

int N, C;

struct Freq {
    int n, i, f;

    Freq(int n, int i): n(n), i(i), f(1) {
    }

    static bool compare(Freq* l, Freq* r) {
        return l->f == r->f ? l->i < r->i : l->f > r->f;
    }
};

int min(int i, int j) {
    return i < j ? i : j;
}

template <typename T, int S>
void msrt(T* a, int n, bool (*f) (T, T)) {
    T b[S];

    for (int i, j, s = 1; s < n; s *= 2) {
        for (int p = 0; p < n;) {
            int l = p;
            int m = min(p += s, n) - 1;
            int h = min(p += s, n) - 1;

            for (i = l; i <= h; i++)
                b[i] = a[i];

            for (i = l, j = m + 1; i <= m && j <= h;)
                a[l++] = f(b[i], b[j]) ? b[i++] : b[j++];

            while (i <= m)
                a[l++] = b[i++];

            while (j <= h)
                a[l++] = b[j++];
        }
    }
}

template <typename K, typename V, int S>
struct Map {
    V b[S];

    V& operator[](K k) {
        return b[k%S];
    }
};

Map<int, Freq*, H> mp;

int main() {
    scanf("%d %d", &N, &C);

    Freq* F[Z];

    for (int n, i = 0; i < N; i++) {
        scanf("%d", &n);

        Freq*& f = mp[n];

        if (f)
            f->f++;
        else
            f = new Freq(n, i);

        F[i] = f;
    }

    msrt<Freq*, Z>(F, N, Freq::compare);

    for (int i = 0; i < N; i++)
        printf("%d ", F[i]->n);
    printf("\n");

    return 0;
}
