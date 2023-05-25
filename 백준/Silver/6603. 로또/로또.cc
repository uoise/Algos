#include <cstdio>

int n, v[13], r[6];
void sol(int dep, int pos) {
  if (dep == 6) {
    for (int i = 0; i < 6; i++) printf("%d ", r[i]);
    printf("\n");
    return;
  }
  for (int i = pos; i < n; i++) {
    r[dep] = v[i];
    sol(dep + 1, i + 1);
  }
}

int main() {
  while (1) {
    scanf("%d", &n);
    if (!n) break;
    for (int i = 0; i < n; i++) scanf("%d", &v[i]);
    sol(0, 0);
    printf("\n");
  }
}