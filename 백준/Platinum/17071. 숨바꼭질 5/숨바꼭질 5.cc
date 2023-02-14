#include <cstdio>
#include <cstring>
#include <queue>

constexpr int MX = 5e5;
std::queue<std::pair<int, int>> q;
int n, k, c, t;
int v[MX + 1][2];
void clc(const int& x) {
  if (x >= 0 && x <= MX && v[x][t % 2] > t) {
    v[x][t % 2] = t;
    q.push({x, t});
  }
}

int sol() {
  if (n == k) return 0;
  memset(v, 0x3f, sizeof v);
  q.push({n, v[n][0] = 0});
  while (!q.empty()) {
    c = q.front().first, t = q.front().second + 1;
    q.pop();
    clc(c - 1), clc(c + 1), clc(c * 2);
  }

  for (int i = 0; i <= MX; i++) {
    k += i;
    if (k > MX) break;
    if (v[k][i % 2] <= i) return i;
  }
  return -1;
}

int main() {
  scanf("%d %d", &n, &k);
  printf("%d", sol());
}