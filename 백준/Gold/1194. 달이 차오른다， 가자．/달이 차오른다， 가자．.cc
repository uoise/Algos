#include <cctype>
#include <cstdio>
#include <queue>

constexpr int yy[] = {1, 0, -1, 0}, xx[] = {0, 1, 0, -1};
struct lk {
  int y, x, k;
};

std::queue<lk> q;
char v[51][51];
int n, m, b[51][51][1 << 7];
int sol() {
  scanf("%d %d", &n, &m);
  for (int y = 0; y < n; y++) {
    scanf("%s", v[y]);
    for (int x = 0; x < m; x++) {
      if (v[y][x] != '0') continue;
      q.push({y, x, 0});
      v[y][x] = '.';
      b[y][x][0] = 1;
    }
  }

  while (q.size()) {
    auto [y, x, k] = q.front();
    q.pop();
    int ak = k;
    if (islower(v[y][x])) ak |= (1 << (v[y][x] - 'a'));
    for (int d = 0; d < 4; d++) {
      int ay = y + yy[d], ax = x + xx[d];
      if (ay < 0 || ay >= n || ax < 0 || ax >= m) continue;
      char& a = v[ay][ax];
      if (a == '1') return b[y][x][k];
      if (a == '#') continue;
      if (isupper(a) && (ak & (1 << (a - 'A'))) == 0) continue;
      if (b[ay][ax][ak]) continue;
      q.push({ay, ax, ak});
      b[ay][ax][ak] = b[y][x][k] + 1;
    }
  }
  return -1;
}

int main() { printf("%d", sol()); }