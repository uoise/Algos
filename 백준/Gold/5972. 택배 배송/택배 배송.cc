#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <unordered_map>

std::priority_queue<std::pair<int, int>> q;
std::unordered_map<int, int> vv[50001];
int dv[50001];
void addOrMin(std::unordered_map<int, int>& m, int pos, int val) {
  m[pos] = (m.find(pos) == m.end()) ? val : std::min(m[pos], val);
}

int main() {
  int n, m, s, e, w, x;
  scanf("%d %d", &n, &m);
  while (m--) {
    scanf("%d %d %d", &s, &e, &w);
    addOrMin(vv[s], e, w);
    addOrMin(vv[e], s, w);
  }

  memset(dv, 0x3f, sizeof dv);

  dv[1] = 0;
  q.push({-dv[1], 1});
  while (!q.empty()) {
    w = -q.top().first, s = q.top().second;
    q.pop();
    for (const auto& p : vv[s]) {
      e = p.first, x = p.second;
      if (dv[e] <= w + x) continue;
      dv[e] = w + x;
      q.push({-dv[e], e});
    }
  }

  printf("%d", dv[n]);
}