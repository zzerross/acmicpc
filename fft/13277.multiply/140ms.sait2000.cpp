// sait2000, // https://www.acmicpc.net/source/8991111
#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>

using namespace std;

#define MAXL 300000
#define MDGTL 9
#define MAXN 131072

typedef int i32;
typedef long long i64;

i32 A[MAXN];
i32 B[MAXN];
i32 T[MAXN];
i32 C0[MAXN];
i32 C1[MAXN];
i32 C2[MAXN];
i32 R[MAXN];

/* p0 < p1, b < p0, p1, p2 */
const i32 p0 = 1070727169, pr0 = 11;
const i32 p1 = 1071513601, pr1 = 23;
const i32 p2 = 1073479681, pr2 = 11;

int ceil2pow(int a){
    --a;
    a |= a >> 1;
    a |= a >> 2;
    a |= a >> 4;
    a |= a >> 8;
    a |= a >> 16;
    return a + 1;
}

i32 powmod(i64 a, i64 b, i32 m) {
    i64 r = 1;
    for ( ; b; b >>= 1) {
        if (b & 1) r = r * a % m;
        a = a * a % m;
    }
    return r;
}

i32 invmod(i32 a, i32 p) {
    return powmod(a, p - 2, p);
}

void vecmod(int n, i32 *AT, const i32 *AF, i32 m) {
    for (int i = 0; i < n; ++i) {
        AT[i] = AF[i] % m;
    }
}

void vecimulmod(int n, i32 *AT, const i32 *AF, i32 m) {
    for (int i = 0; i < n; ++i) {
        AT[i] = (i64)AT[i] * AF[i] % m;
    }
}

void fft(int n, i32 *A, i32 m, i32 pr, bool inv) {
    i32 w = powmod(pr, m / n, m);
    if (inv) { w = invmod(w, m); }

    for (int i = 1, j = 0; i < n; ++i) {
        int k = n >> 1;
        for ( ; j >= k; k >>= 1) {
            j -= k;
        }
        j += k;
        if (i > j) {
            swap(A[i], A[j]);
        }
    }

    for (int ts = 1; ts < n; ts <<= 1) {
        i32 xstep = powmod(w, (n >> 1) / ts, m);
        for (int i = 0; i < n; i += ts) {
            i32 x = 1;
            for ( ; !(i & ts); ++i, x = (i64)x * xstep % m) {
                i32 diff = (i64)A[i | ts] * x % m;
                if ((A[i | ts] = A[i] - diff) < 0) A[i | ts] += m;
                if ((A[i] += diff) >= m) A[i] -= m;
            }
        }
    }

    if (inv) {
        i32 invn = invmod(n, m);
        for (int i = 0; i < n; ++i) {
            A[i] = (i64) A[i] * invn % m;
        }
    }
}

int readnum(int dgtl, i32 *A) {
    string s;
    int j = 0;
    cin >> s;
    for (int i = s.size(); i > 0; ++j, i -= dgtl) {
        if (i < (int)s.size()) {
            s[i] = '\0';
        }
        A[j] = atoi(s.c_str() + max(i - dgtl, 0));
    }
    return j;
}

int main() {
    int dgtl = 9;
    int na = readnum(dgtl, A);
    int nb = readnum(dgtl, B);
    int n = ceil2pow(na + nb);

    vecmod(n, C0, A, p0);
    fft(n, C0, p0, pr0, false);
    vecmod(n, T, B, p0);
    fft(n, T, p0, pr0, false);
    vecimulmod(n, C0, T, p0);
    fft(n, C0, p0, pr0, true);

    vecmod(n, C1, A, p1);
    fft(n, C1, p1, pr1, false);
    vecmod(n, T, B, p1);
    fft(n, T, p1, pr1, false);
    vecimulmod(n, C1, T, p1);
    fft(n, C1, p1, pr1, true);

    vecmod(n, C2, A, p2);
    fft(n, C2, p2, pr2, false);
    vecmod(n, T, B, p2);
    fft(n, T, p2, pr2, false);
    vecimulmod(n, C2, T, p2);
    fft(n, C2, p2, pr2, true);

    /* garner */ {
        const i32 b = 1000000000;
        i32 c0 = 0, c1 = 0, c2 = 0;
        const i32 iu1p1 = invmod(p0, p1);
        const i32 iu2p2 = invmod((i64)p0 * p1 % p2, p2);
        const i32 ibp0 = invmod(b, p0);
        const i32 ibp1 = invmod(b, p1);
        const i32 ibp2 = invmod(b, p2);
        for (int i = 0; i < n; ++i) {
            i32 r0 = C0[i] + c0; if (r0 > p0) r0 -= p0;
            i32 r1 = C1[i] + c1; if (r1 > p1) r1 -= p1;
            i32 r2 = C2[i] + c2; if (r2 > p2) r2 -= p2;
            i32 v0 = r0;
            i32 v1 = (i64)(r1 - v0 + p1) * iu1p1 % p1;
            i32 v2 = (i64)(r2 - ((i64)v1 * p0 + v0) % p2 + p2) * iu2p2 % p2;
            i32 d = (((i64)v2 * p1 + v1) % b * p0 + v0) % b;
            R[i] = d;
            r0 -= d; if (r0 < 0) r0 += p0; c0 = (i64)r0 * ibp0 % p0;
            r1 -= d; if (r1 < 0) r1 += p1; c1 = (i64)r1 * ibp1 % p1;
            r2 -= d; if (r2 < 0) r2 += p2; c2 = (i64)r2 * ibp2 % p2;
        }
    }

    /* print */ {
        int iend = n;
        for ( ; iend > 0 && R[iend - 1] == 0; --iend) {}
        cout << R[iend - 1];
        for (int i = iend - 2; i >= 0; --i) {
            cout << setfill('0') << setw(dgtl) << R[i];
        }
        cout << endl;
    }

    return 0;
}
