#include <algorithm>
#include <cstdio>

int v[1000], n, x = 1;
int sol() {
  for (int i = 0; i < n; i++) {
    if (x < v[i]) return x;
    x += v[i];
  }
  return x;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  std::sort(v, v + n);
  printf("%d", sol());
}