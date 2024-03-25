#include <cstdio>
#include <queue>

struct pf {
  int m[5], s;
};

constexpr int OP[] = {60, 10, -10, 1, -1};
pf r[61];
bool b[61];
void bfs() {
  std::queue<pf> q;
  q.push({0, 0, 0, 0, 0, 0});
  b[0] = 1;
  while (!q.empty()) {
    for (int i = 4; i >= 0; i--) {
      pf c = q.front();
      c.s += OP[i], c.m[i]++;
      if (c.s < 0 || c.s > 60 || b[c.s]) continue;
      r[c.s] = c, b[c.s] = 1;
      q.push(c);
    }
    q.pop();
  }
}

int main() {
  bfs();
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, m;
    scanf("%d", &n);
    m = n % 60, n /= 60;
    printf("%d", r[m].m[0] + n);
    for (int i = 1; i < 5; i++) printf(" %d", r[m].m[i]);
    printf("\n");
  }
}