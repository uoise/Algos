#include <algorithm>
#include <cstdio>
#include <queue>

std::priority_queue<int> q[2];
int n, m, c, x, r;
int main() {
  scanf("%d %d", &n, &m);
  while (n--) {
    scanf("%d", &c);
    q[c > 0].push(std::abs(c));
  }
  
  for (int j = 0; j < 2; j++) {
    while (!q[j].empty()) {
      c = 0;
      for (int i = 0; i < m && !q[j].empty(); i++) {
        c = std::max(c, q[j].top());
        x = std::max(c, x);
        q[j].pop();
      }
      r += (c << 1);
    }
  }
  
  printf("%d", r - x);
}