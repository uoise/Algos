#include <algorithm>
#include <cstdio>
#include <unordered_set>

constexpr int MX = 1001;
std::unordered_set<int> r;
int n, v[MX][4], gv[MX];
bool clc(int a, int b) {
  return !((v[b][3] > v[a][3] && v[a][2] < v[b][2] && v[a][1] > v[b][1] && v[b][0] < v[a][0]) ||
           (v[a][3] > v[b][3] && v[b][2] < v[a][2] && v[b][1] > v[a][1] && v[b][0] > v[a][0]) ||
           (v[b][1] > v[a][3] || v[b][0] > v[a][2] || v[a][1] > v[b][3] ||v[b][2] < v[a][0]));
}

int fnd(int x) {
  if (x == gv[x]) return x;
  return gv[x] = fnd(gv[x]);
}

void mks(int x, int y) {
  int gx = fnd(x), gy = fnd(y);
  if (gx != gy && clc(x, y)) gv[gx] = gy;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d %d %d", &v[i][0], &v[i][1], &v[i][2], &v[i][3]);
    gv[i] = i;
  }
  for (int i = 0; i <= n; i++)
    for (int j = i + 1; j <= n; j++) mks(i, j);
  for (int i = 0; i <= n; i++) r.insert(fnd(i));
  printf("%d", r.size() - 1);
}