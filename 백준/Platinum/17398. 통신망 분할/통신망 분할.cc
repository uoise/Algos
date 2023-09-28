#include <cstdio>
#include <stack>

constexpr int MX = 1e6 + 1;

std::stack<int> stk;
bool bv[MX];
int n, m, gv[MX], cv[MX], ev[MX][2];
int fnd(const int& x) {
  if (x == gv[x]) return x;
  return gv[x] = fnd(gv[x]);
}

long long mks(int x, int y) {
  x = fnd(x), y = fnd(y);
  if (x == y) return 0;
  long long r = 1LL * cv[x] * cv[y];
  cv[y] += cv[x];
  gv[x] = y;
  return r;
}

int main() {
  int q, o;
  long long r = 0;
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1; i <= m; i++) scanf("%d %d", &ev[i][0], &ev[i][1]);
  while (q--) {
    scanf("%d", &o);
    bv[o] = 1;
    stk.push(o);
  }
  for (int i = 1; i <= n; i++) gv[i] = i, cv[i] = 1;
  for (int i = 1; i <= m; i++) if (!bv[i]) mks(ev[i][0], ev[i][1]);
  while (!stk.empty()) {
    q = stk.top();
    stk.pop();
    r += mks(ev[q][0], ev[q][1]);
  }
  printf("%lld", r);
}