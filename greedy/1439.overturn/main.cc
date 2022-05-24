#include <cstdio>

using namespace std;

int main() {
  char s[1000001];
  scanf("%s", s);

  int c[2] = { 0, };

  for (int i = 0; s[i]; i++)
    if (!i || s[i] != s[i-1])
      c[s[i] == '1']++;

  printf("%d\n", c[0] < c[1] ? c[0] : c[1]);

  return 0;
}
