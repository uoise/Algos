#include <cstdio>
#include <queue>

std::priority_queue<std::pair<int, int>> q;
int n, d, w, v[1001], r;
int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("%d %d", &d, &w);
    q.push({w, -d});
  }
  while (!q.empty()) {
    for (int i = -q.top().second; i; i--) {
      if (!v[i]) {
        r += v[i] = q.top().first;
        break;
      }
    }
    q.pop();
  }
  printf("%d", r);
}