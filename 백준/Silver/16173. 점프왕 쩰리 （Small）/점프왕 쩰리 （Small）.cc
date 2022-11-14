#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int xx[2] = {1, 0}, yy[2] = {0, 1}, n;
vector<vector<int>> vv, bv;

bool bfs() {
  queue<pair<int, int>> q;
  q.push({0, 0});
  while (!q.empty()) {
    int cx = q.front().first, cy = q.front().second;
    int cv = vv[cx][cy];
    bv[cx][cy] = 1;
    q.pop();
    for (int i = 0; i < 2; i++) {
      int nx = cx + xx[i] * cv, ny = cy + yy[i] * cv;
      if (nx == n - 1 && ny == n - 1) return true;
      if (nx < n && ny < n && !bv[nx][ny]) q.push({nx, ny});
    }
  }
  return false;
}

string sol() {
  vv.assign(n, vector<int>(n, 0));
  bv.assign(n, vector<int>(n, 0));
  for (auto& v : vv)
    for (auto& i : v) cin >> i;
  return bfs() ? "HaruHaru" : "Hing";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  cout << sol();
}