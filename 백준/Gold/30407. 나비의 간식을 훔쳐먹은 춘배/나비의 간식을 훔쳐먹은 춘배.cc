#include <algorithm>
#include <cstdio>
#include <queue>

struct cat {
  int t, h, d, e;
};

std::queue<cat> q;
int n, h, d, k, rv[20], r;
int sol() {
  int t, th, e, dam;
  q.push({0, h, d, 2});
  while (!q.empty()) {
    t = q.front().t, h = q.front().h, d = q.front().d, e = q.front().e;
    q.pop();
    if (t == n) {
      r = std::max(r, h);
      continue;
    }

    dam = e == 1 ? 0 : rv[t];
    
    th = h - std::max(dam - d, 0) / 2;
    if (th > 0) {
      q.push({t + 1, th, d, e == 1 ? 0 : e});
    }

    th = h - std::max(dam - (d + k), 0);
    if (th > 0) {
      q.push({t + 1, th, d + k, e == 1 ? 0 : e});
    }

    th = h - std::max(dam - d, 0);
    if (e == 2 && th > 0) {
      q.push({t + 1, th, d, 1});
    }
  }

  return r == 0 ? -1 : r;
}

int main() {
  scanf("%d %d %d %d", &n, &h, &d, &k);
  for (int i = 0; i < n; i++) scanf("%d", &rv[i]);
  printf("%d", sol());
}