#include <cstdio>

int n, m, x, k, t, r;
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d", &k);
    t = 200001;
    for (int j = 0; j < k; j++) {
      scanf("%d", &x);
      if (x > t) r = 1;
      t = x;
    }
  }
  printf("%s", r ? "No" : "Yes");
}