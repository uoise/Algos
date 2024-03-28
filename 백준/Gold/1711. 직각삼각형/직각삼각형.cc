#include <cstdio>

int n, r;
long long v[1501][2], l[1501][1501];
long long len(int a, int b) {
  if (l[a][b]) return l[a][b];
  return l[a][b] = (v[a][0] - v[b][0]) * (v[a][0] - v[b][0]) +
                   (v[a][1] - v[b][1]) * (v[a][1] - v[b][1]);
}

bool sol(int a, int b, int c) {
  auto x = len(a, b), y = len(b, c), z = len(a, c);
  return (x + y == z) || (y + z == x) || (z + x == y);
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lld %lld", &v[i][0], &v[i][1]);
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      for (int k = j + 1; k < n; k++)
        if (sol(i, j, k)) ++r;
  printf("%d", r);
}