#include <cstdio>
#include <cstring>

int n, x, y, aa[4], bb[4];
char sol() {
  memset(aa, 0, sizeof aa);
  memset(bb, 0, sizeof bb);
  scanf("%d", &x);
  while (x--) {
    scanf("%d", &y);
    ++aa[y - 1];
  }
  scanf("%d", &x);
  while (x--) {
    scanf("%d", &y);
    ++bb[y - 1];
  }
  for (int i = 3; i >= 0; i--) {
    if (aa[i] > bb[i])
      return 'A';
    else if (aa[i] < bb[i])
      return 'B';
  }
  return 'D';
}

int main() {
  scanf("%d", &n);
  while (n--) printf("%c\n", sol());
}