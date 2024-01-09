#include <algorithm>
#include <cstdio>
#include <functional>
using namespace std;
constexpr int MX = 101;
pair<int, int> v[MX];
int n, d[MX], r;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    v[i] = {max(x, y), min(x, y)};
  }
  sort(v, v + n, greater<>());
  for (int i = 0; i < n; i++) {
    d[i] = 1;
    for (int j = 0; j < i; j++)
      if (v[i].second <= v[j].second) d[i] = max(d[i], d[j] + 1);
    r = max(r, d[i]);
  }
  printf("%d", r);
}