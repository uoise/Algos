#include <algorithm>
#include <cstdio>
#include <queue>

bool bv[501][1001];
struct tp {
  int v[3];
  bool& fnd() const { return bv[v[0]][v[1]]; }
  bool chk() const { return v[0] == v[1] && v[0] == v[2]; }
  void srt() { std::sort(v, v + 3); }
};

std::queue<tp> q;
tp c, a;
bool sol() {
  scanf("%d %d %d", &c.v[0], &c.v[1], &c.v[2]);
  if (c.chk()) return 1;
  c.srt();
  c.fnd() = 1;
  q.push(c);
  while (!q.empty()) {
    c = q.front();
    q.pop();
    for (int i = 0; i < 3; i++) {
      if (!c.v[i]) continue;
      for (int j = 0; j < 3; j++) {
        if (i == j || c.v[i] > c.v[j]) continue;
        a = {c.v[i] * 2, c.v[j] - c.v[i], c.v[3 - (i + j)]};
        a.srt();
        if (a.chk()) return 1;
        if (a.fnd()) continue;
        a.fnd() = 1;
        q.push(a);
      }
    }
  }
  return 0;
}

int main() { printf("%d", sol()); }