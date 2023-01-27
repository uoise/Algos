#include <algorithm>
#include <cstdio>
#include <queue>

using namespace std;

pair<int, int> v[200000];
priority_queue<int> q;
int n;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d %d", &v[i].first, &v[i].second);
  sort(v, v + n);
  for (int i = 0; i < n; i++) {
    q.push(-v[i].second);
    if (i && (-q.top() <= v[i].first)) q.pop();
  }
  printf("%d", q.size());
}