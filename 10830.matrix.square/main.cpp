#include <stdio.h>

typedef long long i64;

struct Matrix {
    int size;
    i64 buf[5][5];

    Matrix(int s, bool i = false): size(s) {
        if (i) {
            for (int i = 0; i < size; i++)
                for (int j = 0; j < size; j++)
                    buf[i][j] = i == j;
        }
    }

    inline i64 mod(const i64& x) {
        return x % 1000UL;
    }

    Matrix& read() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                scanf("%lld", &buf[i][j]);

                buf[i][j] = mod(buf[i][j]);
            }
        }

        return *this;
    }

    Matrix operator*(const Matrix& o) {
        Matrix r(size);

        for (int i = 0; i < size; i++) {
            for ( int j = 0; j < size; j++) {
                r.buf[i][j] = 0;

                for (int x = 0; x < size; x++)
                    r.buf[i][j] = mod(r.buf[i][j] + mod(buf[i][x] * o.buf[x][j]));
            }
        }

        return r;
    }

    Matrix pow(i64 n) {
#if 0 // recursive
        if (n == 1)
            return *this;

        if (n % 2)
            return *this * pow(n - 1);

        Matrix p = pow(n / 2);

        return p * p;
#else
        Matrix r(size, true);

        for (; 0 < n; n /= 2) {
            if (n % 2)
                r = r * *this;

            *this = *this * *this;
        }

        return r;
#endif
    }

    void dump() {
        for (int i = 0; i < size; i++) {
            for ( int j = 0; j < size; j++)
                printf("%lld ", buf[i][j]);

            printf("\n");
        }
    }
};

int main() {
    i64 N, M;

    scanf("%lld %lld", &N, &M);

    Matrix m(N);

    m.read().pow(M).dump();

    return 0;
}
