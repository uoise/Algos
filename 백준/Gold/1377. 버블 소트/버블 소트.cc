#include <algorithm>
#include <cstdio>
std::pair<int, int> v[500001];
int n, r;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i].first);
    v[i].second = i;
  }
  std::sort(v, v + n);
  for (int i = 0; i < n; i++) r = std::max(r, v[i].second - i);
  printf("%d", r + 1);
}