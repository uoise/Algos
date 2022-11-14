#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define iip pair<int, int>
using namespace std;

const int MX = 2001, INF = 2e9;
int N, M, T, S, G, H;
vector<int> dst[3];

void djs(int beg, int pos, vector<vector<iip>>& grp) {
  priority_queue<iip, vector<iip>, greater<>> pq;
  dst[pos][beg] = 0;
  pq.push({0, beg});
  while (!pq.empty()) {
    const int cur = pq.top().second, cst = pq.top().first;
    pq.pop();
    for (const auto& nxt : grp[cur]) {
      if (dst[pos][nxt.first] > cst + nxt.second) {
        dst[pos][nxt.first] = cst + nxt.second;
        pq.push({dst[pos][nxt.first], nxt.first});
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int testcase;
  cin >> testcase;
  while (testcase--) {
    cin >> N >> M >> T;
    int a, b, d, D, trs[T];
    vector<vector<iip>> grp(N + 1);
    for (int i = 0; i < 3; i++) {
      dst[i].clear();
      dst[i].resize(N + 1, INF);
    }

    cin >> S >> G >> H;
    for (int i = 0; i < M; i++) {
      cin >> a >> b >> d;
      if (a == H && b == G || a == G && b == H) D = d;
      grp[a].push_back({b, d});
      grp[b].push_back({a, d});
    }

    for (int i = 0; i < T; i++) cin >> trs[i];
    sort(trs, trs + T);
    djs(S, 0, grp);
    djs(G, 1, grp);
    djs(H, 2, grp);

    for (const int& i : trs)
      if ((dst[0][i] == dst[0][H] + dst[1][i] + D) ||
          (dst[0][i] == dst[0][G] + dst[2][i] + D))
        cout << i << " ";
    cout << "\n";
  }
}