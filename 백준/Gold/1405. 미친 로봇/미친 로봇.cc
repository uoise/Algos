#include <cstdio>

constexpr int yy[] = {1, 0, -1, 0}, xx[] = {0, 1, 0, -1};

int n;
bool bv[29][29];
double v[4];
double dfs(int d, int y, int x) {
  if (!d) return 1;
  double r = 0.0;
  bv[y][x] = 1;
  for (int i = 0; i < 4; i++)
    if (!bv[y + yy[i]][x + xx[i]]) r += (v[i] * dfs(d - 1, y + yy[i], x + xx[i]));
  bv[y][x] = 0;
  return r;
}

double sol() {
  if (n < 2) return 1;
  return dfs(n, 14, 14);
}

int main() {
  scanf("%d %lf %lf %lf %lf", &n, &v[1], &v[3], &v[0], &v[2]);
  for (int i = 0; i < 4; i++) v[i] /= 100;
  printf("%.10lf", sol());
}