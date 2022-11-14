#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
using llp = pair<ll, ll>;
struct bec {
  int b, e;
  double c;
  bec(int b = 0, int e = 0, double c = 0) : b(b), e(e), c(c) {}
  bool operator<(const bec& x) { return c < x.c; }
};
vector<bec> ev;
vector<int> pv;

double len(const llp& x, const llp& y) {
  return sqrt(pow(x.first - y.first, 2) + pow(x.second - y.second, 2));
}
int fnd(const int x) {
  if (x == pv[x]) return x;
  return pv[x] = fnd(pv[x]);
}
bool mks(int x, int y) {
  x = fnd(x), y = fnd(y);
  if (x == y) return false;
  pv[x] = y;
  return true;
}

int main() {
  int N, M;
  double r = 0;
  scanf("%d %d", &N, &M);
  llp vv[N + 1];
  for (int i = 1; i <= N; i++) scanf("%d %d", &vv[i].first, &vv[i].second);

  for (int i = 1; i <= N; i++)
    for (int j = i + 1; j <= N; j++)
      if (i != j) ev.push_back({i, j, len(vv[i], vv[j])});

  sort(ev.begin(), ev.end());
  pv.resize(N + 1);
  for (int i = 0; i <= N; i++) pv[i] = i;
  int x, y;
  for (int i = 0; i < M; i++) {
    scanf("%d %d", &x, &y);
    mks(x, y);
  }

  for (const auto& cur : ev)
    if (mks(cur.b, cur.e)) r += cur.c;

  printf("%.2lf", r);
}