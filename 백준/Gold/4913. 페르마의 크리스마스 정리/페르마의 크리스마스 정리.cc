#include <algorithm>
#include <cstdio>

constexpr int MX = 1e6;

bool pr[MX];
int s[MX], c[MX];
void init() {
  pr[0] = pr[1] = 1;
  for (int i = 2; i * i < MX; i++) {
    if (!pr[i])
      for (int j = i * i; j < MX; j += i) pr[j] = 1;
  }

  c[2] = 1;
  for (int i = 1; i < MX; i++) {
    s[i] += s[i - 1] + !pr[i];
    c[i] += c[i - 1] + (!pr[i] && (i % 4 == 1));
  }
}

int main() {
  init();
  while (1) {
    int l, u, x, y;
    scanf("%d %d", &l, &u);
    if (l == -1 && u == -1) break;
    x = s[std::max(1, u)] - s[std::max(1, l - 1)];
    y = c[std::max(1, u)] - c[std::max(1, l - 1)];
    printf("%d %d %d %d\n", l, u, x, y);
  }
}