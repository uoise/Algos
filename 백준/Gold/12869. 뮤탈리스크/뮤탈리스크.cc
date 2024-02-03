#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;
struct hs {
  int x, y, z;
  hs operator-(const hs& o) const {
    return {max(x - o.x, 0), max(y - o.y, 0), max(z - o.z, 0)};
  }
  bool operator!() const { return !(x || y || z); }
};

queue<hs> q;
hs o[] = {{9, 3, 1}, {9, 1, 3}, {3, 1, 9}, {3, 9, 1}, {1, 3, 9}, {1, 9, 3}};
int bv[66][66][66];
int sol(hs c) {
  if (!c) return 0;
  bv[c.x][c.y][c.z] = 1;
  q.push(c);
  while (!q.empty()) {
    c = q.front();
    q.pop();
    for (const hs& l : o) {
      hs a = c - l;
      int& b = bv[a.x][a.y][a.z];
      if (b) continue;
      b = bv[c.x][c.y][c.z] + 1;
      if (!a) return b - 1;
      q.push(a);
    }
  }
  return -1;
}

int main() {
  int n, s[3] = {0, 0, 0};
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &s[i]);
  printf("%d", sol({s[0], s[1], s[2]}));
}