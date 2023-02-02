#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

priority_queue<int> q;
int n, k, v[10000], r, t;
int main() {
  scanf("%d\n%d", &n, &k);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  sort(v, v + n);
  for (int i = 1; i < n; i++) {
    t = v[i] - v[i - 1];
    if (t) {
      r += t;
      q.push(t);
    }
  }

  while (--k && !q.empty()) {
    r -= q.top();
    q.pop();
  }
  printf("%d", r);
}