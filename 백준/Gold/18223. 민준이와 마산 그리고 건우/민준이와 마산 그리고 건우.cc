#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

constexpr int MX = 5001;

struct cw {
  int c, w;
  bool operator<(const cw& o) const { return w > o.w; }
};

vector<cw> vv[MX];
priority_queue<cw> q;
int dv[MX];
int sol(int s, int e) {
  memset(dv, 0x3f, sizeof dv);
  dv[s] = 0;
  q.push({s, dv[s]});
  while (!q.empty()) {
    auto [c, w] = q.top();
    q.pop();
    if (w > dv[c]) continue;
    for (auto [a, m] : vv[c]) {
      if (dv[a] <= w + m) continue;
      dv[a] = w + m;
      q.push({a, dv[a]});
    }
  }
  return dv[e];
}

int main() {
  int v, e, p, a, b, c;
  scanf("%d %d %d", &v, &e, &p);
  while (e--) {
    scanf("%d %d %d", &a, &b, &c);
    vv[a].push_back({b, c});
    vv[b].push_back({a, c});
  }
  printf("%s", (sol(1, v) == sol(1, p) + sol(p, v)) ? "SAVE HIM" : "GOOD BYE");
}