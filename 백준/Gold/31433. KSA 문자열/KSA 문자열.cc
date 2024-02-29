#include <algorithm>
#include <cstdio>
#include <cstring>

constexpr char s[] = "KSA";
char x[500001];
int n, p[3] = {0, 1, 2}, r[3];
int main() {
  scanf("%s", x);
  n = strlen(x);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 3; j++)
      if (s[p[j]] == x[i]) p[j] = ++p[j] % 3, ++r[j];

  for (int i = 0; i < 3; i++) r[i] = (n - std::min(n - i, r[i])) * 2;
  printf("%d", std::min({r[0], r[1], r[2]}));
}