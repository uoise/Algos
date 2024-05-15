#include <cmath>
#include <cstdio>
#include <string>

void han(int n, int s, int m, int e) {
  if (!n) return;
  han(n - 1, s, e, m);
  printf("%d %d\n", s, e);
  han(n - 1, m, s, e);
}

int main() {
  int n;
  scanf("%d", &n);
  auto r = std::to_string(pow(2, n));
  r = r.substr(0, r.find('.'));
  r[r.length() - 1] -= 1;
  printf("%s\n", r.c_str());
  if (n < 21) han(n, 1, 2, 3);
}