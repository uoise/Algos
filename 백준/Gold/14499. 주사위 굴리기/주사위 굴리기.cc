#include <algorithm>
#include <cstdio>

using namespace std;

int n, m, x, y, k, o, vv[21][21], dv[6];
void sol() {
  if (o == 1) {
    if (x + 1 >= m) return;
    swap(dv[0], dv[3]);
    swap(dv[3], dv[5]);
    swap(dv[5], dv[2]);
    ++x;
  } else if (o == 2) {
    if (x - 1 < 0) return;
    swap(dv[0], dv[2]);
    swap(dv[2], dv[5]);
    swap(dv[5], dv[3]);
    --x;
  } else if (o == 3) {
    if (y - 1 < 0) return;
    swap(dv[0], dv[4]);
    swap(dv[4], dv[5]);
    swap(dv[5], dv[1]);
    --y;
  } else {
    if (y + 1 >= n) return;
    swap(dv[0], dv[1]);
    swap(dv[1], dv[5]);
    swap(dv[5], dv[4]);
    ++y;
  }

  if (!vv[y][x]) {
    vv[y][x] = dv[5];
  } else {
    dv[5] = vv[y][x];
    vv[y][x] = 0;
  }

  printf("%d\n", dv[0]);
}

int main() {
  scanf("%d %d %d %d %d", &n, &m, &y, &x, &k);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) scanf("%d", &vv[i][j]);
  for (int i = 0; i < k; i++) {
    scanf("%d", &o);
    sol();
  }
}