#include <cstdio>

int xx[2] = {1, 0}, yy[2] = {0, 1}, vv[64][64], n;
bool bv[64][64], rr;

void dfs(const int cx, const int cy) {
  if (rr) return;
  if (cx == n - 1 && cy == n - 1) {
    printf("HaruHaru");
    rr = true;
    return;
  }
  int nx, ny, cv = vv[cx][cy];
  bv[cx][cy] = true;
  for (int i = 0; i < 2; i++) {
    nx = cx + xx[i] * cv, ny = cy + yy[i] * cv;
    if (nx < n && ny < n && !bv[nx][ny]) dfs(nx, ny);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) scanf("%d", &vv[i][j]);
  dfs(0, 0);
  if (!rr) printf("Hing");
}