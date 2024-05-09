#include <cstdio>
#include <queue>

constexpr int MA = 1e6 + 1;
std::queue<std::pair<int, bool>> q;
int s, e, v[MA][2], a;
int sol() {
  scanf("%d %d", &s, &e);
  v[s][1] = 1;
  q.push({s, 1});
  while (q.size()) {
    const auto [c, b] = q.front();
    q.pop();
    if (c == e) return v[e][b] - 1;
    a = c * 2;
    if (a < MA && !v[a][b]) q.push({a, b}), v[a][b] = v[c][b] + 1;
    a = c + 1;
    if (a < MA && !v[a][b]) q.push({a, b}), v[a][b] = v[c][b] + 1;
    a = c * 10;
    if (b && a < MA && !v[a][0]) q.push({a, 0}), v[a][0] = v[c][b] + 1;
  }
  return -1;
}

int main() { printf("%d", sol()); }