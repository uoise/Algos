#include <algorithm>
#include <cstdio>

using namespace std;

int n, mx, mn, vv[3], dx[3][2], dm[3][2];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", &vv[0], &vv[1], &vv[2]);
    for (int i = 0; i < 3; i++) {
      mx = dx[1][0], mn = dm[1][0];
      for (int j = max(0, i - 1); j < min(3, i + 2); j++)
        mx = max(mx, dx[j][0]), mn = min(mn, dm[j][0]);
      dx[i][1] = mx + vv[i], dm[i][1] = mn + vv[i];
    }
    for (int i = 0; i < 3; i++) dx[i][0] = dx[i][1], dm[i][0] = dm[i][1];
  }
  mx = dx[0][0], mn = dm[0][0];
  for (int i = 1; i < 3; i++) mx = max(mx, dx[i][0]), mn = min(mn, dm[i][0]);
  printf("%d %d", mx, mn);
}