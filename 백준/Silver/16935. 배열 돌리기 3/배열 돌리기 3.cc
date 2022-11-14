#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> vv, qv;
int n, m, r, rt;

void rud() {
  if (!rt)
    for (int y = 0; y < n / 2; y++)
      for (int x = 0; x < m; x++) swap(vv[y][x], vv[(n - 1) - y][x]);
  else
    for (int y = 0; y < m / 2; y++)
      for (int x = 0; x < n; x++) swap(qv[y][x], qv[(m - 1) - y][x]);
}
void rlr() {
  if (!rt)
    for (int x = 0; x < m / 2; x++)
      for (int y = 0; y < n; y++) swap(vv[y][x], vv[y][(m - 1) - x]);
  else
    for (int x = 0; x < n / 2; x++)
      for (int y = 0; y < m; y++) swap(qv[y][x], qv[y][(n - 1) - x]);
}
void rrr() {
  if (!rt) {
    for (int y = 0; y < n; y++)
      for (int x = 0; x < m; x++) qv[x][(n - 1) - y] = vv[y][x];
    rt = 1;
  } else {
    for (int y = 0; y < m; y++)
      for (int x = 0; x < n; x++) vv[x][(m - 1) - y] = qv[y][x];
    rt = 0;
  }
}
void rrl() {
  if (!rt) {
    for (int y = 0; y < n; y++)
      for (int x = 0; x < m; x++) qv[(m - 1) - x][y] = vv[y][x];
    rt = 1;
  } else {
    for (int y = 0; y < m; y++)
      for (int x = 0; x < n; x++) vv[(n - 1) - x][y] = qv[y][x];
    rt = 0;
  }
}
void rcw() {
  if (!rt) {
    // 1 4
    for (int y = 0; y < n / 2; y++)
      for (int x = 0; x < m / 2; x++) swap(vv[y][x], vv[y + (n / 2)][x]);
    // 1 3
    for (int y = n / 2; y < n; y++)
      for (int x = 0; x < m / 2; x++) swap(vv[y][x], vv[y][x + (m / 2)]);
    // 1 2
    for (int y = 0; y < n / 2; y++)
      for (int x = m / 2; x < m; x++) swap(vv[y][x], vv[y + (n / 2)][x]);
  } else {
    // 1 4
    for (int y = 0; y < m / 2; y++)
      for (int x = 0; x < n / 2; x++) swap(qv[y][x], qv[y + (m / 2)][x]);
    // 1 3
    for (int y = m / 2; y < m; y++)
      for (int x = 0; x < n / 2; x++) swap(qv[y][x], qv[y][x + (n / 2)]);
    // 1 2
    for (int y = 0; y < m / 2; y++)
      for (int x = n / 2; x < n; x++) swap(qv[y][x], qv[y + (m / 2)][x]);
  }
}
void rcr() {
  if (!rt) {
    // 1 2
    for (int y = 0; y < n / 2; y++)
      for (int x = m / 2; x < m; x++) swap(vv[y][x], vv[y + (n / 2)][x]);
    // 1 3
    for (int y = n / 2; y < n; y++)
      for (int x = 0; x < m / 2; x++) swap(vv[y][x], vv[y][x + (m / 2)]);
    // 1 4
    for (int y = 0; y < n / 2; y++)
      for (int x = 0; x < m / 2; x++) swap(vv[y][x], vv[y + (n / 2)][x]);
  } else {
    // 1 2
    for (int y = 0; y < m / 2; y++)
      for (int x = n / 2; x < n; x++) swap(qv[y][x], qv[y + (m / 2)][x]);
    // 1 3
    for (int y = m / 2; y < m; y++)
      for (int x = 0; x < n / 2; x++) swap(qv[y][x], qv[y][x + (n / 2)]);
    // 1 4
    for (int y = 0; y < m / 2; y++)
      for (int x = 0; x < n / 2; x++) swap(qv[y][x], qv[y + (m / 2)][x]);
  }
}

void sol() {
  vv.assign(n, vector<int>(m, 0));
  qv.assign(m, vector<int>(n, 0));
  for (auto& v : vv)
    for (auto& i : v) cin >> i;

  int x;
  for (int i = 0; i < r; i++) {
    cin >> x;
    if (x == 1)
      rud();
    else if (x == 2)
      rlr();
    else if (x == 3)
      rrr();
    else if (x == 4)
      rrl();
    else if (x == 5)
      rcw();
    else
      rcr();
  }

  const auto& rv = (rt ? qv : vv);
  for (const auto& v : rv) {
    for (const auto& i : v) cout << i << ' ';
    cout << '\n';
  }
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> r;
  sol();
}
