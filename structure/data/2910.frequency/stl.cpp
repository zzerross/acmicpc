#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

#define S 1000

int N, C;

struct Freq {
    int n, i, f;

    Freq(int n, int i): n(n), i(i), f(1) {
    }

    static bool compare(const Freq* l, const Freq* r) {
        return l->f == r->f ? l->i < r->i : l->f > r->f;
    }
};

int main() {
    scanf("%d %d", &N, &C);

    Freq* F[S];
    map<int, Freq*> mp;
    map<int, Freq*>::iterator it;

    for (int n, i = 0; i < N; i++) {
        scanf("%d", &n);

        it = mp.find(n);

        if (it == mp.end()) {
            F[i] = mp[n] = new Freq(n, i);
        } else {
            (F[i] = it->second)->f++;
        }
    }

    sort(F, F + N, Freq::compare);

    for (int i = 0; i < N; i++)
        printf("%d ", F[i]->n);
    printf("\n");

    return 0;
}
