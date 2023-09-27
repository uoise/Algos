#include <cstdio>
#include <cstring>

using ll = long long;

int n, vv[10];
bool ev[10][10], bv[10];
ll gcd(const ll& x, const ll& y) { return y ? gcd(y, x % y) : x; }
void dfs(const int& c, const int& m) {
  if (bv[c]) return;
  vv[c] *= m;
  bv[c] = 1;
  for (int i = 0; i < n; i++) if (ev[i][c]) dfs(i, m);
}

int main() {
  int a, b, p, q, x, y, g;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) vv[i] = 1;
  for (int i = 1; i < n; i++) {
    scanf("%d %d %d %d", &a, &b, &p, &q);
    g = gcd(p, q);
    x = vv[b] * (p / g), y = vv[a] * (q / g);
    g = gcd(x, y);
    dfs(a, x / g);
    dfs(b, y / g);
    memset(bv, 0, sizeof bv);
    ev[a][b] = ev[b][a] = 1;
  }

  for (int i = 0; i < n; i++) printf("%d ", vv[i]);
}