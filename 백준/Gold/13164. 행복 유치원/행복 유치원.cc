#include <cstdio>
#include <queue>

std::priority_queue<int> q;
int n, k, r, x, l;
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    l = x;
    scanf("%d", &x);
    if (!i) continue;
    q.push(x - l);
    r += x - l;
  }

  while (!q.empty() && --k) {
    r -= q.top();
    q.pop();
  }

  printf("%d", r);
}