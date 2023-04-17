#include <algorithm>
#include <cstdio>

long long x, y, w, s, r;
int main() {
  scanf("%d %d %d %d", &x, &y, &w, &s);
  if (x < y) std::swap(x, y);
  r = std::min((x + y) * w, y * s + (x - y) * w);
  r = std::min(r, (x - y) % 2 ? (x - 1) * s + w : x * s);
  printf("%lld", r);
}