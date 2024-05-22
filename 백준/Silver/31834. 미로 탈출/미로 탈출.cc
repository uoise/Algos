#include <algorithm>
#include <cstdio>

int sol() {
  int n, s, e;
  scanf("%d %d %d", &n, &s, &e);
  if ((s == 1 && e == n) || (s == n && e == 1)) return 0;
  else if ((s == 1 || s == n) || (std::abs(s - e) == 1)) return 1;
  return 2;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) printf("%d\n", sol());
}