#include <cstdio>

int t, k, p[101], n[101], r[10001];
int main() {
  scanf("%d %d", &t, &k);
  for (int i = 0; i < k; i++) scanf("%d %d", &p[i], &n[i]);
  r[0] = 1;
  for (int i = 0; i < k; i++) {
    for (int j = t; j; j--) {
      int s = 0;
      for (int k = 0; k < n[i]; k++) {
        s += p[i];
        if (j - s >= 0 && r[j - s]) r[j] += r[j - s];
      }
    }
  }
  printf("%d", r[t]);
}