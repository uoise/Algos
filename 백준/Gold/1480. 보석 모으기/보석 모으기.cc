#include <algorithm>
#include <cstdio>
#include <cstring>

int n, m, c, v[13], r[11][21][1 << 13];
int sol(int p, int w, int b) {
  if (p == m) return -1;
  if (b == (1 << n) - 1) return 0;
  int& t = r[p][w][b];
  if (t != -1) return t;
  t = 0;
  for (int i = 0; i < n; i++) {
    if ((b & (1 << i)) || (v[i] > c)) continue;
    t = std::max(t, 1 + ((w + v[i] > c) ? sol(p + 1, v[i], b | (1 << i))
                                        : sol(p, w + v[i], b | (1 << i))));
  }
  return t;
}

int main() {
  memset(r, -1, sizeof r);
  scanf("%d %d %d", &n, &m, &c);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  printf("%d", sol(0, 0, 0));
}