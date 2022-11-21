#include <algorithm>
#include <iostream>
#define x first
#define y second

using namespace std;

int n, l, res;
int sol() {
  pair<int, int> vv[n];
  for (auto& p : vv) cin >> p.x >> p.y;
  sort(vv, vv + n);

  int beg, end = -2e9, cnt = 0, chk = 0;
  for (const auto& p : vv) {
    if (end < p.x) {
      res += cnt;
      beg = p.x;
      chk = 0;
    }
    if (end < p.y) {
      cnt = (p.y - beg) / l;
      if ((p.y - beg) % l) ++cnt;
      end = beg + cnt * l;
      chk = 1;
    }
  }
  if (chk) res += cnt;
  return res;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> l;
  cout << sol();
}