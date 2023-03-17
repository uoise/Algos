#include <algorithm>
#include <cstdio>
#include <cstring>

constexpr int INF = 0x3f3f3f3f;
int vv[501][501], dv[501];
int TC, n, m, w, s, e, t;

bool b_fs() {
  dv[1] = 0;
  for (int i = 1; i <= n; i++) {
    for (s = 1; s <= n; s++) {
      for (e = 1; e <= n; e++) {
        if (vv[s][e] >= INF) continue;
        if (dv[e] > dv[s] + vv[s][e]) {
          dv[e] = dv[s] + vv[s][e];
          if (i == n) return 1;
        }
      }
    }
  }
  return 0;
}

int main() {
  scanf("%d", &TC);
  while (TC--) {
    memset(vv, 0x3f, sizeof vv);
    memset(dv, 0x3f, sizeof dv);
    scanf("%d %d %d", &n, &m, &w);
    for (int i = 0; i < m + w; i++) {
      scanf("%d %d %d", &s, &e, &t);
      vv[s][e] = std::min(vv[s][e], i < m ? t : -t);
      if (i < m) vv[e][s] = std::min(vv[e][s], t);
    }
    printf("%s\n", b_fs() ? "YES" : "NO");
  }
}