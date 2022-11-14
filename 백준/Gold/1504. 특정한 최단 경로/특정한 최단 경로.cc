#include <iostream>
#include <queue>
#include <vector>
#define INF 21000000000000
#define ll long long
#define iip pair<int, int>
#define llp pair<ll, ll>

using namespace std;
vector<vector<iip>> grp(801);
vector<ll> dst[3];

int V, E, V1, V2;
ll R1, R2;
void djs(int beg, int pos) {
  dst[pos].resize(V + 1, INF);
  priority_queue<llp, vector<llp>, greater<>> pq;
  pq.push({0, beg});
  dst[pos][beg] = 0;
  while (!pq.empty()) {
    const ll cur = pq.top().second, cst = pq.top().first;
    pq.pop();
    for (const auto& nxt : grp[cur])
      if (dst[pos][nxt.first] > nxt.second + cst) {
        dst[pos][nxt.first] = nxt.second + cst;
        pq.push({dst[pos][nxt.first], nxt.first});
      }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> V >> E;
  int a, b, c;
  for (int i = 0; i < E; i++) {
    cin >> a >> b >> c;
    grp[a].push_back({b, c});
    grp[b].push_back({a, c});
  }
  cin >> V1 >> V2;
  djs(1, 0);
  djs(V1, 1);
  djs(V2, 2);

  R1 = dst[0][V1] + dst[1][V2] + dst[2][V];
  R2 = dst[0][V2] + dst[2][V1] + dst[1][V];
  if (R1 > R2) R1 = R2;
  if (R1 >= INF)
    cout << -1;
  else
    cout << R1;
}