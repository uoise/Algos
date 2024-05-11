#include <bitset>
#include <cstdio>

std::bitset<50> v[1001], c;
int n, k, m, x;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &k);
    for (int j = 0; j < k; j++) {
      scanf("%d", &x);
      v[i][x - 1] = 1;
    }
  }
    
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    c.set();
    scanf("%d", &k);
    for (int j = 0; j < k; j++) {
      scanf("%d", &x);
      c[x - 1] = 0;
    }
    x = n;
    for (int j = 0; j < n; j++)
      if ((v[j] & c).count()) --x;
    printf("%d\n", x);
  }
}