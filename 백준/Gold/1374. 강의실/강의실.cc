#include <cstdio>
#include <queue>

std::priority_queue<std::pair<int, int>> u;
std::priority_queue<int> q;
int main() {
  int n, x, s, e;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", &x, &s, &e);
    u.push({-s, -e});
  }

  while (!u.empty()) {
    s = -u.top().first, e = -u.top().second;
    u.pop();
    if (!q.empty() && -q.top() <= s) q.pop();
    q.push(-e);
  }

  printf("%d", q.size());
}