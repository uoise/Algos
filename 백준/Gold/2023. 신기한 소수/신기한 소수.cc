#include <cstdio>

void dfs(const int& x, const int& d) {
  for (int i = 2; i * i <= x; i++) if (!(x % i)) return;
  if (!d) printf("%d\n", x);
  else for (int i = 1; i < 10; i++) dfs(x * 10 + i, d - 1);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 2; i < 8; i++) dfs(i, n - 1);
}