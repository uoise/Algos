#include <algorithm>
#include <cstdio>
#include <queue>

std::priority_queue<int> q;
std::pair<int, int> v[100001];
int n, d, r, s, e;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &s, &e);
    v[i].second = std::min(s, e), v[i].first = std::max(s, e);
  }
  scanf("%d", &d);
  std::sort(v, v + n);
  for (int i = 0; i < n; i++) {
    if (v[i].second - v[i].first > d) continue;
    q.push(-v[i].second);
    while (!q.empty() && v[i].first + q.top() > d) q.pop();
    r = std::max(r, (int)q.size());
  }

  printf("%d", r);
}