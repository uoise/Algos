#include <cstdio>
int n, x;
bool v[2001];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    v[x + 1000] = 1;
  }
  for (int i = 0; i < 2001; i++)
    if (v[i]) printf("%d ", i-1000);
}