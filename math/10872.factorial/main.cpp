#include <iostream>

using namespace std;

int main() {
    int r = 1, n;

    for (scanf("%d", &n); 0 < n; r *= n--);

    cout << r << endl;

    return 0;
}
