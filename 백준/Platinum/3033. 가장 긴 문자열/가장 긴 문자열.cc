#include <cstdio>
#include <vector>

using ll = long long;

constexpr int MX = 2e5 + 3;
std::vector<int> hs[MX];
char s[MX];
int n;
ll abm(const ll& x) {
  if (x > 0) return x % MX;
  return ((-x / MX + 1) * MX + x) % MX;
}

bool cmp(const int& x, const int& y, const int& len) {
  for (int i = 0; i < len; i++)
    if (s[x + i] != s[y + i]) return 0;
  return 1;
}

bool chk(const int len) {
  for (auto& v : hs) v.clear();
  ll h = 0, p = 1;
  for (int i = 0; i <= n - len; i++) {
    if (!i) {
      for (int j = 0; j < len; j++) {
        h = abm(h + p * s[len - 1 - j]);
        if (j < len - 1) p = abm(p << 1);
      }
    } else {
      h = abm((h - p * s[i - 1]) * 2 + s[i + len - 1]);
    }
    if (!hs[h].empty())
      for (const int& t : hs[h])
        if (cmp(i, t, len)) return 1;
    hs[h].push_back(i);
  }
  return 0;
}

int main() {
  scanf("%d %s", &n, s);
  int b = 0, e = n, r = 0;
  while (b + 1 < e) {
    int m = (b + e) / 2;
    if (chk(m)) {
      b = m;
    } else
      e = m;
  }
  printf("%d", b);
}