// https://greeksharifa.github.io/algorithm%20&%20data%20structure/2018/07/07/algorithm-FFT
// http://topology-blog.tistory.com/6

#define _USE_MATH_DEFINES

#include <cstdio>
#include <iostream>

#include <vector>

#include <complex>
#include <algorithm> // for reverse

using namespace std;

#define ll long long

template <typename T>
T power_of_2_ge_than(T n) {
        T ret = 1;
            while (n > ret) ret <<= 1;
                return ret;
}

vector<int> string_to_vi(string& s) {
        vector<int> ret(s.size());
            for (int i = 0; i < s.size(); i++)
                        ret[i] = s[i] - '0';
                return ret;
}

typedef complex<double> base;

void fft(vector<base> &a, bool inv) {
    int n = (int)a.size();
    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        while (!((j ^= bit) & bit)) bit >>= 1;
        if (i < j) swap(a[i], a[j]);
    }
    for (int i = 1; i < n; i <<= 1) {
        double x = (inv ? 1 : -1) * M_PI / i;
        base w = { cos(x), sin(x) };
        for (int j = 0; j < n; j += i << 1) {
            base th(1);
            for (int k = 0; k < i; k++) {
                base tmp = a[i + j + k] * th;
                a[i + j + k] = a[j + k] - tmp;
                a[j + k] += tmp;
                th *= w;
            }
        }
    }
    if (inv) {
        for (int i = 0; i < n; i++) a[i] /= n;
    }
}

vector<int> multiply(vector<int> &A, vector<int> &B) {
    vector<base> a(A.begin(), A.end());
    vector<base> b(B.begin(), B.end());
    int n = power_of_2_ge_than(max(a.size(), b.size())) * 2;

    a.resize(n);	b.resize(n);
    fft(a, false);	fft(b, false);

    for (int i = 0; i < n; i++)
        a[i] *= b[i];
    fft(a, true);

    vector<int> ret(n);
    for (int i = 0; i < n; i++)
        ret[i] = (int)round(a[i].real());
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string a, b;

    cin >> a >> b;

    vector<int> A = string_to_vi(a);
    vector<int> B = string_to_vi(b);

    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    vector<int> ret = multiply(A, B);

    int i = 0;
    while (i < ret.size()) {
        if (ret[i] >= 10) {
            if (i == ret.size() - 1)
                ret.push_back(ret[i] / 10);
            else
                ret[i + 1] += ret[i] / 10;
            ret[i] %= 10;
        }
        ++i;
    }

    reverse(ret.begin(), ret.end());

    bool start = false;
    for (auto elem : ret) {
        if (elem)
            start = true;

        if (start)
            cout << elem;
    }

    if (!start)
        cout << '0';

    cout << endl;

    return 0;
}
