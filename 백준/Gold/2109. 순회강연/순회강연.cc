#include <cstdio>
#include <queue>

std::priority_queue<std::pair<int, int>> q;
bool v[10001];
int n, p, d, r;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &p, &d);
    q.push({p, -d});
  }
  while (!q.empty()) {
    p = q.top().first, d = -q.top().second;
    q.pop();
    for (int i = d; i; i--) {
      if (v[i]) continue;
      v[i] = 1, r += p;
      break;
    }
  }
  
  printf("%d", r);
}