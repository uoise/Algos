#include <cstdio>
#include <queue>
#include <vector>

constexpr int MN = 101001;
std::vector<int> v[MN];
std::queue<int> q;
int n, b[MN];
int sol() {
  b[1] = 1;
  q.push(1);
  while (q.size()) {
    int c = q.front();
    q.pop();
    for (int a : v[c]) {
      if (b[a]) continue;
      b[a] = b[c] + 1;
      if (a == n) return b[a] / 2 + 1;
      q.push(a);
    }
  }
  return -1;
}

int main() {
  int m, k;
  scanf("%d %d %d", &n, &k, &m);
  int t = n + 1, x;
  for (int i = 0; i < m; i++, t++) {
    for (int i = 0; i < k; i++) {
      scanf("%d", &x);
      v[t].push_back(x), v[x].push_back(t);
    }
  }
  printf("%d", n == 1 ? 1 : sol());
}