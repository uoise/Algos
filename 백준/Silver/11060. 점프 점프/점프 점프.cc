#include <cstdio>
#include <cstring>
#include <queue>

std::queue<int> q;
int n, c, v[1001], b[1001];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  memset(b, 0x3f, sizeof b);
  b[0] = 0;
  q.push(0);
  while (!q.empty()) {
    c = q.front();
    q.pop();
    for (int i = 1; i <= v[c]; i++) {
      if (c + i >= n || b[c] + 1 >= b[c + i]) continue;
      b[c + i] = b[c] + 1;
      q.push(c + i);
    }
  }
  printf("%d", b[n - 1] == 0x3f3f3f3f ? -1 : b[n - 1]);
}