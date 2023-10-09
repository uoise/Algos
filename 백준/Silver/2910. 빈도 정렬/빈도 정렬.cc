#include <cstdio>
#include <queue>
#include <unordered_map>

struct vlr {
  int v, l, r;
  bool operator<(const vlr& o) const { return r == o.r ? l > o.l : r < o.r; }
};

std::unordered_map<int, std::pair<int, int>> m;
std::priority_queue<vlr> q;
int n, c;
int main() {
  int x;
  scanf("%d %d", &n, &c);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    auto f = m.find(x);
    if (f == m.end())
      m.insert({x, {i, 1}});
    else
      f->second.second++;
  }

  for (const auto& p : m) q.push({p.first, p.second.first, p.second.second});
  while (!q.empty()) {
    auto p = q.top();
    q.pop();
    while (p.r--) printf("%d ", p.v);
  }
}