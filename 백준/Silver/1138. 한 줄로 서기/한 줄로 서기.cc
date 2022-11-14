#include <cstdio>

int n, vv[10], rv[10];
void sol() {
  for (int i = 0; i < n; i++) scanf("%d", &vv[i]);
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int p = 0; p < n; p++)
      if (!rv[p])
        if (cnt++ == vv[i]) {
          rv[p] = i + 1;
          break;
        }
  }
  for (int i = 0; i < n; i++) printf("%d ", rv[i]);
}

int main() {
  scanf("%d", &n);
  sol();
}