#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;
vector<tuple<int, int, int>> iv;
vector<int> pv;

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

void inp() {
  int n;
  cin >> n;
  pv.resize(n);
  pair<int, int> vv[3][n];

  for (int i = 0; i < n; i++) {
    cin >> vv[0][i].first >> vv[1][i].first >> vv[2][i].first;
    pv[i] = vv[0][i].second = vv[1][i].second = vv[2][i].second = i;
  }

  for (int j = 0; j < 3; j++) {
    sort(vv[j], vv[j] + n);
    for (int i = 1; i < n; i++)
      iv.push_back({vv[j][i].first - vv[j][i - 1].first, vv[j][i - 1].second,
                    vv[j][i].second});
  }
  sort(iv.begin(), iv.end());
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long res = 0;
  inp();
  for (const auto& cur : iv) {
    const int bb = get<1>(cur), ee = get<2>(cur);
    if (mks(bb, ee)) res += get<0>(cur);
  }
  cout << res;
}