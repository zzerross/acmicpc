#include <cstdio>
#include <algorithm>

#if 0 < DEBUG
#define pr0(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#define pr0(fmt, ...)
#endif

#if 1 < DEBUG
#define pr1(fmt, ...) printf(fmt, ##__VA_ARGS__)
#else
#define pr1(fmt, ...)
#endif

using namespace std;

typedef long long i64;

#define POINTS 100000

const i64 DISTANCE = 20000000000;

struct Point {
    i64 x, y;
} gPoints[POINTS];

int gNumOfPoints;
int gNumOfTests = 1;

void dump(const char* s = nullptr) {
#if DEBUG
    pr0("%8s: \n", s ? s : __func__);

    for (int i = 0; i < gNumOfPoints; i++)
        pr0("%8s: %2lld %2lld\n", "", gPoints[i].x, gPoints[i].y);

    pr0("\n");
#endif
}

void dump(int* a, int n, const char* s = nullptr) {
#if DEBUG
    pr0("%8s: \n", s ? s : __func__);

    for (int i = 0; i < n; i++)
        pr0("%8s: %2lld %2lld\n", "", gPoints[a[i]].x, gPoints[a[i]].y);

    pr0("\n");
#endif
}

i64 _min(i64 i, i64 j) {
    return i < j ? i : j;
}

bool lefty(struct Point& a, struct Point& b) {
    return a.x < b.x;
}

bool lower(int i, int j) {
    return gPoints[i].y < gPoints[j].y;
}

i64 square(i64 i) {
    return i * i;
}

i64 distance(int i, int j) {
    return square(gPoints[i].x - gPoints[j].x) + square(gPoints[i].y - gPoints[j].y);
}

i64 closest3(int left, int right) {
    i64 r = DISTANCE;

    for (int i = left; i < right; i++)
        for (int j = i + 1; j <= right; j++)
            r = _min(r, distance(i, j));

    return r;
}

i64 closest(int left, int right) {
    int size = right - left + 1;
    if (size <= 3)
        return closest3(left, right);

    int middle = left + size / 2;
    i64 leftDistance = closest(left, middle);
    i64 rightDistance = closest(middle + 1, right);
    i64 result = _min(leftDistance, rightDistance);

    i64 line = (gPoints[middle].x + gPoints[middle+1].x) / 2;
    int candidates[size], numOfCandidates = 0;

    for (int i = left; i <= right; i++)
        if (square(line - gPoints[i].x) < result)
            candidates[numOfCandidates++] = i;

    sort(candidates, candidates + numOfCandidates, lower);

    for (int i = 0; i < numOfCandidates - 1; i++) {
        for (int j = i + 1; j < numOfCandidates; j++) {
            i64 yDistance = gPoints[candidates[i]].y - gPoints[candidates[j]].y;
            if (result < square(yDistance))
                break;

            i64 candidateDistance = distance(candidates[i], candidates[j]);
            if (candidateDistance < result)
                result = candidateDistance;
        }
    }

    return result;
}

int main() {
    setbuf(stdout, NULL);

    scanf("%d", &gNumOfTests);

    for (int t = 1; t <= gNumOfTests; t++) {
        scanf("%d", &gNumOfPoints);

        for (int i = 0; i < gNumOfPoints; i++)
            scanf("%lld %lld", &gPoints[i].x, &gPoints[i].y);

        sort(gPoints, gPoints + gNumOfPoints, lefty);

        printf("#%d %lld\n", t, closest(0, gNumOfPoints - 1));
    }

    return 0;
}
