#include <cstdio>
#include <queue>

using namespace std;

constexpr int MX = 100001;
int n, m, k, r = MX, c;
bool v[MX];
queue<pair<int, int>> q;
void sol() {
  q.push({n, 0});
  while (!q.empty()) {
    n = q.front().first, m = q.front().second;
    q.pop();
    v[n] = 1;
    if (r < m) break;
    if (n == k) {
      r = m;
      c++;
    } else {
      ++m;
      if (n - 1 >= 0 && !v[n - 1]) q.push({n - 1, m});
      if (n + 1 < MX && !v[n + 1]) q.push({n + 1, m});
      if (n * 2 < MX && !v[n * 2]) q.push({n * 2, m});
    }
  }
}

int main() {
  scanf("%d %d", &n, &k);
  if (n == k)
    c = 1, r = 0;
  else
    sol();
  printf("%d\n%d", r, c);
}