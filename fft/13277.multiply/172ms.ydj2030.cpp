#include <iostream>
#include <cmath>
#include <complex>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

#define all(v) (v).begin(), (v).end()

typedef complex<double> base;

typedef long long ll;

void fft(vector<base> &a, bool invert)
{
    int n = a.size();
    for(int i = 1, j = 0; i < n; i++)
    {
        int bit = n >> 1;
        for(; j >= bit; bit>>=1) j -= bit;
        j += bit;
        if(i < j) swap(a[i], a[j]);
    }
    for(int len = 2; len <= n; len<<=1)
    {
        double angle = 2*M_PI/len*(invert?-1:1);
        base wlen(cos(angle), sin(angle));
        for(int i = 0; i < n; i += len)
        {
            base w(1);
            for(int j = 0; j < len/2; j++)
            {
                base u = a[i+j], v = a[i+j+len/2]*w;
                a[i+j] = u+v;
                a[i+j+len/2] = u-v;
                w *= wlen;
            }
        }
    }
    if(invert)
    {
        for(int i = 0; i < n; i++) a[i] /= n;
    }
}

void multiply(const vector<int> &a, const vector<int> &b, vector<int> &res)
{
    vector<base> fa(all(a)), fb(all(b));
    int n = 1;
    while(n < a.size() + b.size()) n <<= 1;
    fa.resize(n); fb.resize(n);
    fft(fa, false); fft(fb, false);

    for(int i = 0; i < n; i++) fa[i] *= fb[i];
    fft(fa, true);
    res.resize(n);
    for(int i = 0; i < n; i++) res[i] = int(fa[i].real() + (fa[i].real() > 0 ? 0.5 : -0.5));

    while(res.size() > a.size() + b.size() - 1) res.pop_back();
}

int mystoi(char a, char b)
{
    return (a - '0') * 10 + (b - '0');
}

string itos(int i)
{
    stringstream ss;
    ss << i;
    return ss.str();
}

bool firstprint;

void print(int a)
{
    if(a < 10) printf("0%d", a);
    else printf("%d", a);
}

int main()
{
    string A, B;

    getline(cin, A, ' ');
    getline(cin, B);

    if(A == "0" || B == "0")
    {
        cout << "0";
        return 0;
    }

    if(A.length() % 2) A = "0" + A;
    if(B.length() % 2) B = "0" + B;

    vector<int> a, b, c;
    for(int i = A.length() - 2; i >= 0; i-=2)
    {
        a.push_back(mystoi(A[i], A[i+1]));
    }

    //for(int i = 0; i < a.size(); i++)
    //cout << a[i] << ' ';
    //cout << endl;

    for(int i = B.length() - 2; i >= 0; i-=2)
    {
        b.push_back(mystoi(B[i], B[i+1]));
    }

    //for(int i = 0; i < b.size(); i++)
    //cout << b[i] << ' ';
    //cout << endl;

    multiply(a, b, c);

    vector<ll> ans;

    int s = c.size();

    for(int i = 0; i < s; i++)
    {
        ans.push_back(c[i]);
    }

    //for(int i = 0; i < s; i++)
    //cout << ans[i] << ' ';
    //cout << endl;

    for(int i = 0; i < s - 1; i++)
    {
        ans[i+1] += ans[i] / 100;
        ans[i] = ans[i] % 100;
    }

    //for(int i = 0; i < s; i++)
    //cout << ans[i] << ' ';
    //cout << endl;

    printf("%lld", ans[s-1]);

    for(int i = s - 2; i >= 0; i--)
    {
        print(ans[i]);
    }
    printf("\n");

    return 0;
}
