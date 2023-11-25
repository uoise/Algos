#include <cstdio>
#include <string>

bool sol(int n) {
  if (n < 12) return 1;
  std::string s = std::to_string(n);
  for (int i = 0; i <= s.size() / 2; i++)
    if (s[i] != s[s.size() - 1 - i]) return false;
  return true;
}

bool pr(int n) {
  for (int i = 2; i * i <= n; i++)
    if (!(n % i)) return false;
  return true;
}

int main() {
  int s, e;
  scanf("%d %d", &s, &e);
  if (e > 9999999) e = 9999999;
  for (int i = s; i <= e; i++)
    if (sol(i) && pr(i)) printf("%d\n", i);
  printf("-1");
}