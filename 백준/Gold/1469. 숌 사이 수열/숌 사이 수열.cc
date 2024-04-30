#include <algorithm>
#include <cstdio>

bool d, b[8];
int n, x[8], r[16];
void dfs(int c) {
  if (c == n * 2) {
    for (int i = 0; i < n * 2; i++) printf("%d ", r[i]);
    d = 1;
    return;
  }
  if (d) return;
  if (r[c] != -1) {
    dfs(c + 1);
    return;
  }
  for (int i = 0; i < n; i++) {
    if (b[i] || c + x[i] + 1 >= n * 2 || r[c + x[i] + 1] != -1) continue;
    b[i] = 1, r[c] = r[c + x[i] + 1] = x[i];
    dfs(c + 1);
    b[i] = 0, r[c] = r[c + x[i] + 1] = -1;
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    r[i] = r[i + n] = -1;
    scanf("%d", &x[i]);
  }
  std::sort(x, x + n);
  dfs(0);
  if (!d) printf("-1");
}