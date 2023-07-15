#include <cstdio>
#include <queue>

std::priority_queue<std::pair<int, int>> q;
int n, d, c, t, gv[200001];
long long r;
int fnd(const int& x) {
  if (x == gv[x]) return x;
  return gv[x] = fnd(gv[x]);
}

bool mks(int x, int y) {
  x = fnd(x), y = fnd(y);
  if (x == y) return 0;
  gv[y] = x;
  return 1;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &d, &c);
    gv[i] = i;
    q.push({c, d});
  }

  while (!q.empty()) {
    c = q.top().first, d = q.top().second;
    q.pop();
    if (fnd(d) && mks(gv[d] - 1, d)) r += c;
  }

  printf("%lld", r);
}