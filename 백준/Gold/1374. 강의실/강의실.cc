#include <algorithm>
#include <cstdio>
#include <queue>
std::pair<int, int> v[100001];
std::priority_queue<int> q;
int main() {
  int n, x;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d %d %d", &x, &v[i].first, &v[i].second);
  std::sort(v, v + n);
  for (int i = 0; i < n; i++) {
    if (!q.empty() && -q.top() <= v[i].first) q.pop();
    q.push(-v[i].second);
  }
  printf("%d", q.size());
}