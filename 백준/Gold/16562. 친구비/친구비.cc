#include <iostream>
#include <queue>

constexpr int MX = 1e4 + 1;
std::priority_queue<std::pair<int, int>> q;
int n, m, k, r, gv[MX], wv[MX];
int fnd(const int& x) {
  if (x == gv[x]) return x;
  return gv[x] = fnd(gv[x]);
}

void mks(int x, int y) {
  x = fnd(x), y = fnd(y);
  if (x != y) gv[x] = y;
}

int main() {
  scanf("%d %d %d", &n, &m, &k);
  r = k;
  for (int i = 0; i <= n; i++) gv[i] = i;
  for (int i = 1; i <= n; i++) scanf("%d", &wv[i]);
  int c, w;
  while (m--) {
    scanf("%d %d", &c, &w);
    mks(c, w);
  }
  for (int i = 1; i <= n; i++) q.push({-wv[i], i});
  while (!q.empty()) {
    w = -q.top().first, c = q.top().second;
    q.pop();
    if (fnd(0) == fnd(c)) continue;
    if (k < w) {
      r = -1;
      break;
    }
    mks(0, c);
    k -= w;
  }

  if (r < 0) printf("Oh no");
  else printf("%d", r - k);
}