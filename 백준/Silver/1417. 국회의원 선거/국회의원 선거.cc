#include <cstdio>
#include <queue>

std::priority_queue<int> q;
int n, c, x, r;
int main() {
  scanf("%d %d", &n, &c);
  for (int i = 1; i < n; i++) {
    scanf("%d", &x);
    q.push(x);
  }
  while (!q.empty() && q.top() >= c) {
    x = q.top() - 1;
    q.pop();
    ++c, ++r;
    q.push(x);
  }
  printf("%d", r);
}