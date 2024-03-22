#include <cmath>
#include <cstdio>

long long r = -1, t;
int n, m, cy, cx;
char v[9][10];
bool vld(const long long &x) {
  long long t = sqrt(x);
  return t * t == x;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int y = 0; y < n; y++) scanf("%s", v[y]);
  for (int y = 0; y < n; y++) {
    for (int x = 0; x < m; x++) {
      for (int yy = -n; yy <= n; yy++) {
        for (int xx = -m; xx <= m; xx++) {
          if (!yy && !xx) continue;
          t = 0, cy = y, cx = x;
          while (!(cy < 0 || cy >= n || cx < 0 || cx >= m)) {
            t = t * 10 + (v[cy][cx] - '0');
            if (r < t && vld(t)) r = t;
            cy += yy, cx += xx;
          }
        }
      }
    }
  }

  printf("%lld", r);
}