#include <cstdio>
char n[100001];
int v[10], r;
int main() {
  scanf("%s", n);
  for (int i = 0; n[i] && n[i] != '\0'; i++) v[n[i] - '0']++, r += (n[i] - '0');
  if (!(r % 3) && v[0])
    for (int i = 9; i >= 0; i--)
      while (v[i]--) printf("%d", i);
  else
    printf("-1");
}