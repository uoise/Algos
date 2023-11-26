#include <iostream>
using ll = long long;
using llp = std::pair<ll, ll>;
int ccw(const llp a, const llp b, const llp c) {
  ll r = (b.first - a.first) * (c.second - a.second) -
         (c.first - a.first) * (b.second - a.second);
  return r < 0 ? -1 : (r > 0 ? 1 : 0);
}

int main() {
  std::cin.tie(0)->sync_with_stdio(0);
  llp dv[4];
  for (auto& i : dv) std::cin >> i.first >> i.second;
  std::cout << (((ccw(dv[0], dv[1], dv[2]) * ccw(dv[0], dv[1], dv[3]) < 0) &&
                 (ccw(dv[2], dv[3], dv[0]) * ccw(dv[2], dv[3], dv[1]) < 0))
                    ? 1 : 0);
}