#include <algorithm>
#include <cstdio>

constexpr int MX = (1 << 12) - 1;
bool ev[MX][MX];
long long tr, pr;
int d, u, t, l;
bool vld(int s, int e) { return (e < (1 << d)) && (!ev[s][e]); }
void dfs(int c, int k, long long s) {
  int a = c * 2;
  int b = vld(c, a) && vld(c, a + 1);
  tr = std::max(tr, s), l = c;
  if (vld(c, a)) dfs(a, k + b, s + u + (k + b) * t), pr += 2LL * u;
  if (vld(c, ++a)) dfs(a, k + b, s + u + (k + b) * t), pr += 2LL * u;
}

int main() {
  int n;
  scanf("%d %d %d %d", &d, &n, &u, &t);
  while (n--) {
    int s, e;
    scanf("%d %d", &s, &e);
    ev[s][e] = ev[e][s] = 1;
  }
  dfs(1, 0, 0);
  while (l != 1) pr -= u, l /= 2;
  printf(":blob_twintail_%s:", tr == pr ? "thinking" : (tr < pr) ? "aww" : "sad");
}