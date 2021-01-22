#include <stdio.h>

int min(int i, int j) {
    return i < j ? i : j;
}

int main() {
    int x, y, w, h;

    scanf("%d %d %d %d", &x, &y, &w, &h);

    printf("%d\n", min(min(x, w - x), min(y, h - y)));

    return 0;
}
