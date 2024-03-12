#include <algorithm>
#include <cstdio>

using namespace std;

pair<int, int> pv[11];
bool bv[12];
int n, h, dv[12][12], r, ex, ey, cc = 1;
void btr(int p, int w, int c) {
  if (!p && bv[p]) {
    r = max(r, c);
    return;
  }

  for (int a = 0; a < cc; a++) {
    if (bv[a] || w - dv[p][a] < 0) continue;
    bv[a] = 1;
    btr(a, w + h - dv[p][a], c + 1);
    bv[a] = 0;
  }
}

int main() {
  int m, c;
  scanf("%d %d %d", &n, &m, &h);
  for (int y = 0; y < n; y++) {
    for (int x = 0; x < n; x++) {
      scanf("%d", &c);
      if (!c) continue;
      if (c == 1)
        ey = y, ex = x;
      else
        pv[cc++] = {y, x};
    }
  }

  pv[0] = {ey, ex};
  for (int i = 0; i < cc; i++)
    for (int j = i + 1; j < cc; j++)
      dv[i][j] = dv[j][i] = abs(pv[i].first - pv[j].first) + abs(pv[i].second - pv[j].second);
  btr(0, m, -1);
  printf("%d", r);
}