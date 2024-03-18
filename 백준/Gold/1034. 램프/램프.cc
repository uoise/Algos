#include <algorithm>
#include <bitset>
#include <cstdio>

std::bitset<51> v[51];
char inp[51];
int n, m, k, r;
int sol() {
  for (int i = 0; i < n; i++) {
    int z = m - v[i].count(), c = 0;
    if (z > k || z % 2 != k % 2) continue;
    for (int j = 0; j < n; j++) if (v[i] == v[j]) ++c;
    r = std::max(r, c);
  }
  return r;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int y = 0; y < n; y++) {
    scanf("%s", inp);
    for (int x = 0; x < m; x++) v[y][x] = inp[x] == '1';
  }
  scanf("%d", &k);
  printf("%d", sol());
}