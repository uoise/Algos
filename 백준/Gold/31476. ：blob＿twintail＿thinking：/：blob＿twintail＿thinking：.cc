#include <algorithm>
#include <cstdio>

long long u, t, tr, pr;
int d, ev[4095], l;
bool vld(int s, int e) { return (e < (1 << d)) && (ev[e] != s); }
void dfs(int c, int k, long long s) {
  int a = c * 2;
  int b = vld(c, a) && vld(c, a + 1);
  tr = std::max(tr, s), l = c;
  if (vld(c, a)) dfs(a, k + b, s + u + (k + b) * t), pr += u * 2;
  if (vld(c, ++a)) dfs(a, k + b, s + u + (k + b) * t), pr += u * 2;
}

int main() {
  int n;
  scanf("%d %d %lld %lld", &d, &n, &u, &t);
  while (n--) {
    int s, e;
    scanf("%d %d", &s, &e);
    ev[e] = s;
  }
  dfs(1, 0, 0);
  while (l != 1) pr -= u, l /= 2;
  printf(":blob_twintail_%s:", tr == pr ? "thinking" : (tr < pr) ? "aww" : "sad");
}