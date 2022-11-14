#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> v, r;
vector<vector<int>> grp;
int x, p = 0;
void bfs() {
  v.assign(x + 1, 0);
  grp.assign(x + 1, vector<int>());
  queue<int> q;
  v[x] = 1;
  q.push(x);
  while (!q.empty()) {
    const int& cur = q.front();
    q.pop();
    if (cur % 3 == 0 && !v[cur / 3]) {
      v[cur / 3] = v[cur] + 1;
      grp[cur].push_back(cur / 3);
      q.push(cur / 3);
    }
    if (cur % 2 == 0 && !v[cur / 2]) {
      v[cur / 2] = v[cur] + 1;
      grp[cur].push_back(cur / 2);
      q.push(cur / 2);
    }
    if (cur > 1 && !v[cur - 1]) {
      v[cur - 1] = v[cur] + 1;
      grp[cur].push_back(cur - 1);
      q.push(cur - 1);
    }
    if (v[1]) break;
  }
  cout << v[1] - 1 << '\n';
  v.clear();
}

void dfs(int beg) {
  r.push_back(beg);
  if (beg == 1) {
    for (const int& i : r) cout << i << " ";
    p = 1;
    return;
  }
  if (p == 1) return;
  for (int c : grp[beg]) dfs(c);
  r.pop_back();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> x;
  bfs();
  dfs(x);
}