#include <iostream>
#include <queue>
#include <vector>
#define MX 10001
using namespace std;
vector<pair<int, int>> dp;
vector<int> rr;
int tgt;
bool flg;
char ops[4] = {'L', 'D', 'R', 'S'};
int rgc(const int& x, const int& it) {
  if (it == 0) return (x % 1000 * 10) + (x / 1000);         // L
  if (it == 1) return (x * 2) % 10000;                      // D
  if (it == 2) return (x % 10 * 1000) + (x - x % 10) / 10;  // R
  return x == 0 ? 9999 : x - 1;                             // S
}

void bfs(const int beg) {
  queue<int> q;
  dp[beg] = {1, -1};
  q.push(beg);
  while (!q.empty()) {
    const int cur = q.front();
    if (cur == tgt) return;
    q.pop();
    for (int i = 0; i < 4; i++) {
      const int nxt = rgc(cur, i);
      if (dp[nxt].first == -1) {
        dp[nxt] = {dp[cur].first + 1, i};
        q.push(nxt);
      }
    }
  }
}

void rtt(int cur) {
  if (flg) return;
  rr.push_back(cur);
  if (cur == tgt) {
    for (int i = 1; i < rr.size(); i++) cout << ops[dp[rr[i]].second];
    cout << '\n';
    flg = true;
    return;
  }
  for (int i = 0; i < 4; i++) {
    const int nxt = rgc(cur, i);
    if ((dp[nxt].first == dp[cur].first + 1) && (dp[nxt].second == i)) rtt(nxt);
  }
  rr.pop_back();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int testcase, beg;
  cin >> testcase;
  while (testcase--) {
    dp.assign(MX, {-1, -1});
    flg = false;
    rr.clear();
    cin >> beg >> tgt;
    bfs(beg);
    rtt(beg);
  }
}
