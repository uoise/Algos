#include <cstdio>
#include <queue>
#include <vector>

std::queue<int> q, p;
std::vector<int> vv[1001];
int n, m, bv[1001], o, b, c;
void sol() {
  for (int i = 1; i <= n; i++)
    if (!bv[i]) q.push(i);

  while (!q.empty()) {
    int cur = q.front();
    p.push(cur);
    q.pop();
    for (const auto& nxt : vv[cur]) {
      if (!--bv[nxt]) q.push(nxt);
    }
  }

  if (p.size() == n) {
    while (!p.empty()) {
      printf("%d\n", p.front());
      p.pop();
    }
  } else {
    printf("0");
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d", &o);
    for (int j = 0; j < o; j++) {
      scanf("%d", &c);
      if (j) {
        vv[b].push_back(c);
        ++bv[c];
      }
      b = c;
    }
  }
  sol();
}