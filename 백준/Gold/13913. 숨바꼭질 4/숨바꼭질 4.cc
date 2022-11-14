#include <iostream>
#include <queue>
#include <vector>
#define MX 100001
using namespace std;
bool rr = false;
int n, k;
vector<int> v(MX, -1), r;
void bfs() {
  queue<int> q;
  v[n] = 0;
  q.push(n);
  while (!q.empty()) {
    const int cur = q.front();
    q.pop();
    if (cur == k) break;

    int nxt = cur * 2;
    if (nxt < MX && v[nxt] == -1) {
      v[nxt] = v[cur] + 1;
      q.push(nxt);
    }
    nxt = cur + 1;
    if (nxt < MX && v[nxt] == -1) {
      v[nxt] = v[cur] + 1;
      q.push(nxt);
    }
    nxt = cur - 1;
    if (nxt >= 0 && v[nxt] == -1) {
      v[nxt] = v[cur] + 1;
      q.push(nxt);
    }
  }
}

void rrt(int cur) {
  if (rr) return;
  r.push_back(cur);
  if (cur == k) {
    for (const auto& i : r) cout << i << " ";
    rr = true;
    return;
  }
  if ((cur * 2 < MX) && (v[cur * 2] == v[cur] + 1)) rrt(cur * 2);
  if ((cur + 1 < MX) && (v[cur + 1] == v[cur] + 1)) rrt(cur + 1);
  if ((cur - 1 >= 0) && (v[cur - 1] == v[cur] + 1)) rrt(cur - 1);
  r.pop_back();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> k;
  bfs();
  cout << v[k] << '\n';
  rrt(n);
}