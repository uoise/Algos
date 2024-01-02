#include <algorithm>
#include <cstdio>

using namespace std;

pair<int, int> v[100001];
int n, m, s = -50001, e, t, r;
int main() {
  scanf("%d", &m);
  while (1) {
    scanf("%d %d", &v[n].first, &v[n].second);
    if (!v[n].first && !v[n].second) break;
    if (v[n].second > 0 && v[n].first <= m && v[n].first != n[v].second) ++n;
  }
  sort(v, v + n);
  for (int i = 0; i < n; i++) {
    if (v[i].first > s && v[i].first <= e) {
      t = max(t, v[i].second);
      if (e > t) break;
      if (v[i].second >= m) {
        ++r, e = m;
        break;
      }
      continue;
    }
    ++r, s = e;
    e = t;
  }
  printf("%d", e == m ? r : 0);
}