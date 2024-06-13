#include <cstdio>
#include <vector>

constexpr int MN = 1e6 + 1, DV = 1e9 + 7;

std::vector<int> q;
bool v[8];
int n, m, a[MN], b, t, s, c, r;
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    if (v[a[i] % 7]) continue;
    v[a[i] % 7] = 1;
    ++r;
  }

  for (int i = 0; i < m; i++) {
    scanf("%d", &b);
    t = (b + c) % 7;
    t = (7 - t) % 7;

    if (v[t]) {
      if (r == 1) continue;
      v[t] = 0;
      r -= 1;
    }

    c = (c + b) % 7, s = (s + b) % DV;
  }

  for (int i = 0; i < n; i++) if (v[a[i] % 7]) q.push_back((a[i] + s) % DV);

  printf("%d\n", q.size());
  for (int& i : q) printf("%d ", i);
}