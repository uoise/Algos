#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

struct ti {
  int t, s, e;
  bool operator<(const ti& o) const { return t < o.t; }
};

std::vector<ti> tv;
int n, m, k;
bool vs[1001], ve[1001];
bool vld(int x) {
  int cnt = 1;
  memset(ve, 0, sizeof ve);
  ve[x] = 1;
  for (const auto& [t, a, b] : tv) {
    if (!ve[a]) continue;
    if (!vs[b]) return 0;
    if (!ve[b]) cnt++, ve[b] = 1;
  }
  return cnt == k;
}

int sol() {
  int t, a, b;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < k; i++) {
    scanf("%d", &t);
    vs[t] = 1;
  }
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &t, &a, &b);
    tv.push_back({t, a, b});
  }
  std::sort(tv.begin(), tv.end());
  for (int i = 1; i <= n; i++) if (vs[i] && vld(i)) return i;
  return 0;
}

int main() { printf("%d", sol()); }