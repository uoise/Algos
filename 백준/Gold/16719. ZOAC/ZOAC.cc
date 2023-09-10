#include <cstdio>
#include <cstring>

char z[101];
bool r[101];
int n;
void sol() {
  for (int i = 0; i < n; i++) if (r[i]) printf("%c", z[i]);
  printf("\n");
}

void clc(const int& s, const int& e) {
  int m = s;
  for (int i = s; i <= e; i++) if (z[m] > z[i]) m = i;
  r[m] = 1;
  sol();
  if (m < e) clc(m + 1, e);
  if (m > s) clc(s, m - 1);
}

int main() {
  scanf("%s", z);
  n = strlen(z);
  clc(0, n - 1);
}