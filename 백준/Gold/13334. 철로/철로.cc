#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

priority_queue<int> q;
pair<int, int> v[100001];
int n, d, r, s, e;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &s, &e);
    v[i] = {max(s, e), min(s, e)};
  }
  scanf("%d", &d);
  sort(v, v + n);
  for (int i = 0; i < n; i++) {
    e = v[i].first, s = v[i].second;
    if (s - e > d) continue;
    q.push(-s);
    while (!q.empty() && e + q.top() > d) q.pop();
    r = max(r, (int)q.size());
  }
  printf("%d", r);
}