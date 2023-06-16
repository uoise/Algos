#include <cstdio>

constexpr int MX = 1e5 + 1;
int n, m, x, y, v[MX];
bool b[MX];
void sol() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) v[i] = i;
  while (m--) {
    scanf("%d %d", &x, &y);
    v[x]++, v[y]--;
  }

  for (int i = 1; i <= n; i++) {
    if (b[v[i]]) {
      printf("-1");
      return;
    }
    b[v[i]] = true;
  }

  for (int i = 1; i <= n; i++) printf("%d ", v[i]);
}

int main() { sol(); }