#include <algorithm>
#include <cstdio>

int n, r = 0x3f3f3f3f, v[1001];
int sol(const int& mn, const int& mx) {
  int s = 0;
  for (int i = 0; i < n; i++) {
    if (v[i] < mn) s += (mn - v[i]) * (mn - v[i]);
    if (v[i] > mx) s += (v[i] - mx) * (v[i] - mx);
  }
  return s;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  for (int i = 0; i <= 83; i++) r = std::min(r, sol(i, i + 17));
  printf("%d", r);
}