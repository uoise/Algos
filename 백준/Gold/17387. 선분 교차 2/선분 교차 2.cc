#include <iostream>
using namespace std;
using ll = long long;
using llp = pair<ll, ll>;
int ccw(const llp a, const llp b, const llp c) {
  ll r = (b.first - a.first) * (c.second - a.second) -
         (c.first - a.first) * (b.second - a.second);
  return r < 0 ? -1 : (r > 0 ? 1 : 0);
}

int sol() {
  llp dv[4];
  for (auto& i : dv) cin >> i.first >> i.second;
  const auto lt1 = min(dv[0], dv[1]), lt2 = min(dv[2], dv[3]);
  const auto gt1 = max(dv[0], dv[1]), gt2 = max(dv[2], dv[3]);
  int c1 = ccw(dv[0], dv[1], dv[2]), c2 = ccw(dv[0], dv[1], dv[3]);
  int c3 = ccw(dv[2], dv[3], dv[0]), c4 = ccw(dv[2], dv[3], dv[1]);
  int r1 = c1 * c2, r2 = c3 * c4;
  if (r1 < 0 && r2 < 0) return 1;
  if (!r1 && !r2) return (lt1 <= gt2 && lt2 <= gt1);
  if (!r1) {
    if (!c1) return (lt1 < dv[2] && dv[2] < gt1);
    if (!c2) return (lt1 < dv[3] && dv[3] < gt1);
  }
  if (!r2) {
    if (!c3) return (lt2 < dv[0] && dv[0] < gt2);
    if (!c4) return (lt2 < dv[1] && dv[1] < gt2);
  }
  return 0;
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout.tie(0);
  cout << sol();
}
