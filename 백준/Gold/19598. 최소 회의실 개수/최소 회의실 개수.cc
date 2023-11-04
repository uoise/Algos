#include <algorithm>
#include <cstdio>

std::pair<int, int> v[200001];
int main() {
  int n, s, e, r = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &s, &e);
    v[i * 2] = {s, 1}, v[i * 2 + 1] = {e, -1};
  }
  std::sort(v, v + n * 2);
  s = 0;
  for (int i = 0; i < n * 2; i++) {
    s += v[i].second;
    r = std::max(r, s);
  }

  printf("%d", r);
}