#include <iostream>
#include <queue>
#include <vector>
#define MX 20001
#define INF 210000000
using namespace std;
int V, E, K;
vector<vector<pair<int, int>>> g(MX);
vector<int> dst;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
void sol() {
  dst.resize(V + 1, INF);
  dst[K] = 0;
  pq.push({0, K});
  while (!pq.empty()) {
    const int cst = pq.top().first, cur = pq.top().second;
    pq.pop();
    for (const auto &ne : g[cur]) {
      if (dst[ne.first] > cst + ne.second) {
        dst[ne.first] = cst + ne.second;
        pq.push({dst[ne.first], ne.first});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> V >> E >> K;
  int u, v, w;
  for (int i = 0; i < E; i++) {
    cin >> u >> v >> w;
    g[u].push_back({v, w});
  }
  sol();
  for (int i = 1; i <= V; i++) {
    if (dst[i] == INF)
      cout << "INF\n";
    else
      cout << dst[i] << '\n';
  }
}