#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

constexpr int MX = 10001;
vector<int> grp[MX];
int vst[MX], par[MX];
bool pv[MX];

void mkt(int cur, int prv) {
  vst[cur] = vst[prv] + 1;
  par[cur] = prv;
  for (const auto& nxt : grp[cur])
    if (nxt != prv) mkt(nxt, cur);
}

void inp(const int n) {
  int a, b;
  memset(vst, 0, sizeof vst);
  memset(pv, 0, sizeof pv);
  for (int i = 1; i <= n; i++) grp[i].clear();
  for (int i = 1; i < n; i++) {
    cin >> a >> b;
    grp[a].push_back(b);
    pv[b] = 1;
  }
  for (int i = 1; i <= n; i++)
    if (!pv[i]) a = i;
  mkt(a, 0);
}

int nca(int x, int y) {
  if (vst[x] < vst[y]) swap(x, y);
  while (vst[x] != vst[y]) x = par[x];
  while (x != y) x = par[x], y = par[y];
  return x;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T, n, a, b;
  cin >> T;
  while (T--) {
    cin >> n;
    inp(n);
    cin >> a >> b;
    cout << nca(a, b) << '\n';
  }
}