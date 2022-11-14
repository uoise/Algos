#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<vector<pair<int, int>>> grp;
vector<bool> vst, vse;
int TC;
bool bfs(const int beg) {
  queue<int> q;
  vst[beg] = 1;
  q.push(beg);
  while (!q.empty()) {
    const int cur = q.front();
    q.pop();
    for (const auto& nxt : grp[cur]) {
      if (!vse[nxt.second]) {
        if (vst[nxt.first]) return false;
        vse[nxt.second] = true;
        vst[nxt.first] = true;
        q.push(nxt.first);
      }
    }
  }
  return true;
}
void sol(const int siz) {
  int r = 0;
  for (int i = 1; i <= siz; i++) {
    if (!vst[i])
      if (bfs(i)) r++;
  }
  cout << "Case " << ++TC << ": ";
  if (r == 0)
    cout << "No trees.\n";
  else if (r == 1)
    cout << "There is one tree.\n";
  else
    cout << "A forest of " << r << " trees.\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int n, m, x, y;
  while (1) {
    cin >> n >> m;
    if (n == 0 && m == 0) break;
    grp.assign(n + 1, vector<pair<int, int>>(0));
    vst.assign(n + 1, false);
    vse.assign(m + 1, false);
    while (m--) {
      cin >> x >> y;
      grp[x].push_back({y, m});
      if (x != y) grp[y].push_back({x, m});
    }
    sol(n);
  }
}
