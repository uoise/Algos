#include <cstdio>
#include <queue>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> u, q, t;
int sv[100001];
int main() {
  int n, s, e;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &s, &e);
    u.push({s, e});
  }

  n = 0;
  while (!u.empty()) {
    s = u.top().first, e = u.top().second;
    u.pop();
    while (!q.empty() && q.top().first <= s) {
      t.push({q.top().second, q.top().first});
      q.pop();
    }

    if (!t.empty()) {
      s = t.top().first;
      ++sv[s];
      q.push({e, s});
      t.pop();
    } else {
      ++sv[++n];
      q.push({e, n});
    }
  }

  printf("%d\n", n);
  for (int i = 1; i <= n; i++) printf("%d ", sv[i]);
}