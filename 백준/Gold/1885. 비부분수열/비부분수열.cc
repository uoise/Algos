#include <cstdio>
#include <cstring>

bool b[10001];
int s, k, c, r = 1;
int main() {
  scanf("%d %d", &s, &k);
  for (int i = 0; i < s; i++) {
    int x;
    scanf("%d", &x);
    if (!b[x]) b[x] = 1, ++c;
    if (c != k) continue;
    memset(b, 0, sizeof b);
    c = 0, ++r;
  }
  printf("%d", r);
}