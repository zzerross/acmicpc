#include <cstdio>
#include <algorithm>
#include <stack>

#if 1 <= DEBUG
#define D1(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#define D1(fmt, ...)
#endif

using namespace std;

#define VECTORS 100000

typedef long long i64;

template <typename T, int S>
struct Array {
    int n;
    T buf[S];

    T& operator[](int i) {
        return buf[i];
    }

    T* begin() {
        return buf;
    }

    T* end() {
        return buf + n;
    }
};

template <typename T>
struct Vector2D {
    T x, y;
    T dx, dy;

    Vector2D(T x = 0, T y = 0) {
        init(x, y);
    }

    void init(T x = 0, T y = 0, T dx = 0, T dy = 0) {
        this->x = x;
        this->y = y;
        this->dx = dx;
        this->dy = dy;
    }

    T cross(const Vector2D& o) const {
        return x * o.y - y * o.x;
    }

    T ccw(const Vector2D& o) const {
        return cross(o);
    }

    T ccw(const Vector2D& a, const Vector2D& b) const {
        Vector2D oa = a - *this;
        Vector2D ob = b - *this;

        return oa.cross(ob);
    }

    bool operator<(const Vector2D& o) const {
        if (dy * o.dx != dx * o.dy)
            return dy * o.dx < dx * o.dy;

        return x == o.x ?  y < o.y : x < o.x;
    }

    Vector2D operator-(const Vector2D& o) const {
        return Vector2D<T>(x - o.x, y - o.y);
    }

    void dump(const char* s) {
        D1("%8s: %d %d\n", s, x, y);
    }

    void read() {
        init();

        scanf("%lld %lld", &x, &y);
    }
};

struct Array<Vector2D<i64>, VECTORS> gVectors;

int main() {
    setbuf(stdout, NULL);

    stack<int> stack;

    scanf("%d", &gVectors.n);

    for (int i = 0; i < gVectors.n; i++)
        gVectors[i].read();

    sort(gVectors.begin(), gVectors.end());

    for (int i = 1; i < gVectors.n; i++) {
        gVectors[i].dx = gVectors[i].x - gVectors[0].x;
        gVectors[i].dy = gVectors[i].y - gVectors[0].y;
    }

    sort(gVectors.begin() + 1, gVectors.end());

    stack.push(0);
    stack.push(1);

    for (int next = 2; next < gVectors.n; stack.push(next++)) {
        for (int first, second; 2 <= stack.size();) {
            second = stack.top();
            stack.pop();
            first = stack.top();

            if (0 < gVectors[first].ccw(gVectors[second], gVectors[next])) {
                stack.push(second);
                break;
            }
        }
    }

    printf("%ld\n", stack.size());

    return 0;
}
