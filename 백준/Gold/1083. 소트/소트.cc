#include <cstdio>

int n, v[51], s, t, p;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  scanf("%d", &s);

  for (int i = 0; i < n && s; i++) {
    t = v[i], p = i;
    for (int j = i + 1; j < n && j - i <= s; j++)
      if (t < v[j]) t = v[j], p = j;
    s -= (p - i);
    while (p > i) v[p--] = v[p - 1];
    v[i] = t;
  }

  for (int i = 0; i < n; i++) printf("%d ", v[i]);
}