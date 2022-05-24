#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int tc = 0, nr = 0;

  struct Rank {
    int a;
    int b;
  } ranks[100000];

  for (scanf("%d", &tc); tc--;) {
    scanf("%d", &nr);

    for (int i = 0; i < nr; i++)
      scanf("%d %d", &ranks[i].a, &ranks[i].b);

    sort(ranks, ranks + nr, [](Rank a, Rank b) {
        return a.a < b.a;
    });

    int count = 0, min = nr + 1;
    for (int i = 0; i < nr; i++) {
      if (ranks[i].b < min) {
        min = ranks[i].b;
        count++;
      }
    }

    printf("%d\n", count);
  }

  return 0;
}
