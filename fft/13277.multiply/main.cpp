// sait2000's https://www.acmicpc.net/source/8991111

#include <stdio.h>

#if DEBUG == 1
#define _d0(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#define _d0(fmt, ...)
#endif

using namespace std;

#define MAXL 300000
#define MDGTL 9

typedef long long i32;
typedef long long i64;

template <typename T>
void _pa(const char* s, T* a, size_t n) {
    _d0("%8s: n=%lu, ", s ? s : "", n);

    for (int i = 0; i < n; i++)
        _d0("%d ", a[i]);

    _d0("\n");
}

template <typename T>
void _swap(T& a, T& b){
    T t = a;
    a = b;
    b = t;
}

int _max(int a, int b) {
    return a < b ? b : a;
}

int _strlen(char* s) {
    int n = 0;

    for (; s[n]; n++);

    return n;
}

int _atoi(char* s) {
    int n = 0;

    while (*s)
        (n *= 10) += *s++ - '0';

    return n;
}

template <int S, int D = 9>
struct Integer {
    i32 buf[S];
    size_t len;

    size_t read() {
        char s[S];
        scanf("%s", s);

        for (int i = _strlen(s); 0 < i;) {
            s[i] = '\0';

            buf[len++] = _atoi(s + _max(i -= D, 0));
        }

        return len;
    }
};

Integer<300001> A, B;

/* p0 < p1, b < p0, p1, p2 */
const i32 p0 = 1070727169, pr0 = 11;
const i32 p1 = 1071513601, pr1 = 23;
const i32 p2 = 1073479681, pr2 = 11;

int ceil2pow(int a){
    --a;

    for (int i = 1; i <= 16; i *= 2)
        a |= a >> i;

    return ++a;
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

template <typename T>
T max(T a, T b) {
    return a < b ? b : a;
}

size_t mdigits(size_t a, size_t b) {
    size_t d = 0;

    d += (a == 1 ? 0 : a);
    d += (b == 1 ? 0 : b);

    return max(d, 1UL);
}

#define MAXN 131072
template <typename T, int S = 131072>
struct Vector {
    T buf[S];
    int n;

    Vector(int n): n(n) {
    }

    void mod(const T *a, T m) {
        for (int i = 0; i < n; i++)
            buf[i] = a[i] % m;
    }

    void mulmod(const T* a, T m) {
        for (int i = 0; i < n; i++)
            buf[i] = buf[i] * a[i] % m;
    }

    void fft(i32 m, i32 pr, bool inv) {
        i32 w = powmod(pr, m / n, m);
        if (inv) { w = invmod(w, m); }

        for (int i = 1, j = 0; i < n; ++i) {
            int k = n >> 1;
            for ( ; j >= k; k >>= 1) {
                j -= k;
            }
            j += k;
            if (i > j) {
                _swap(buf[i], buf[j]);
            }
        }

        for (int ts = 1; ts < n; ts <<= 1) {
            i32 xstep = powmod(w, (n >> 1) / ts, m);
            for (int i = 0; i < n; i += ts) {
                i32 x = 1;
                for ( ; !(i & ts); ++i, x = (i64)x * xstep % m) {
                    i32 diff = (i64)buf[i | ts] * x % m;
                    if ((buf[i | ts] = buf[i] - diff) < 0) buf[i | ts] += m;
                    if ((buf[i] += diff) >= m) buf[i] -= m;
                }
            }
        }

        if (inv) {
            i32 invn = invmod(n, m);
            for (int i = 0; i < n; ++i) {
                buf[i] = (i64) buf[i] * invn % m;
            }
        }
    }
};

int main() {
    int n = ceil2pow(A.read() + B.read());

    Vector<i32> v0(n), v1(n), v2(n), t(n), r(n);

    v0.mod(A.buf, p0);
    v0.fft(p0, pr0, false);

    t.mod(B.buf, p0);
    t.fft(p0, pr0, false);

    v0.mulmod(t.buf, p0);
    v0.fft(p0, pr0, true);

    v1.mod(A.buf, p1);
    v1.fft(p1, pr1, false);

    t.mod(B.buf, p1);
    t.fft(p1, pr1, false);

    v1.mulmod(t.buf, p1);
    v1.fft(p1, pr1, true);

    v2.mod(A.buf, p2);
    v2.fft(p2, pr2, false);

    t.mod(B.buf, p2);
    t.fft(p2, pr2, false);

    v2.mulmod(t.buf, p2);
    v2.fft(p2, pr2, true);

    /* garner */ {
        const i32 b = 1000000000;
        i32 c0 = 0, c1 = 0, c2 = 0;
        const i32 iu1p1 = invmod(p0, p1);
        const i32 iu2p2 = invmod((i64)p0 * p1 % p2, p2);
        const i32 ibp0 = invmod(b, p0);
        const i32 ibp1 = invmod(b, p1);
        const i32 ibp2 = invmod(b, p2);
        for (int i = 0; i < n; ++i) {
            i32 r0 = v0.buf[i] + c0; if (r0 > p0) r0 -= p0;
            i32 r1 = v1.buf[i] + c1; if (r1 > p1) r1 -= p1;
            i32 r2 = v2.buf[i] + c2; if (r2 > p2) r2 -= p2;
            i32 v0 = r0;
            i32 v1 = (i64)(r1 - v0 + p1) * iu1p1 % p1;
            i32 v2 = (i64)(r2 - ((i64)v1 * p0 + v0) % p2 + p2) * iu2p2 % p2;
            i32 d = (((i64)v2 * p1 + v1) % b * p0 + v0) % b;
            r.buf[i] = d;
            r0 -= d; if (r0 < 0) r0 += p0; c0 = (i64)r0 * ibp0 % p0;
            r1 -= d; if (r1 < 0) r1 += p1; c1 = (i64)r1 * ibp1 % p1;
            r2 -= d; if (r2 < 0) r2 += p2; c2 = (i64)r2 * ibp2 % p2;
        }
    }

    int iend = n;
    for (; 0 < iend && r.buf[iend - 1] == 0; --iend);

    printf("%lld", r.buf[iend - 1]);

    for (int i = iend - 2; i >= 0; --i)
        printf("%09lld", r.buf[i]);

    printf("\n");

    return 0;
}
