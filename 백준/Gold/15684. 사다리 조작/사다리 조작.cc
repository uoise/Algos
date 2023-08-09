#include <cstdio>

int n, m, h;
bool v[33][11];
bool chk() {
  for (int x = 1; x <= n; x++) {
    m = x;
    for (int y = 1; y <= h; y++) {
      if (v[y][m])
        ++m;
      else if (v[y][m - 1])
        --m;
    }
    if (m != x) return false;
  }
  return true;
}

bool clc(const int& d) {
  if (!d) return chk();

  for (int x = 1; x < n; x++) {
    for (int y = 1; y <= h; y++) {
      if (v[y][x - 1] || v[y][x] || v[y][x + 1]) continue;
      v[y][x] = true;
      if (clc(d - 1)) return true;
      v[y][x] = false;

      while (!v[y][x - 1] && !v[y][x + 1]) ++y;
    }
  }

  return false;
}

int sol() {
  for (int i = 0; i < 4; i++) if (clc(i)) return i;
  return -1;
}

int main() {
  int x, y;
  scanf("%d %d %d", &n, &m, &h);
  while (m--) {
    scanf("%d %d", &y, &x);
    v[y][x] = true;
  }
  printf("%d", sol());
}