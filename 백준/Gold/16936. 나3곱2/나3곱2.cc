#include <cstdio>
#include <queue>

constexpr int MX = 101;

std::queue<long long> q;
int n;
long long v[MX];
bool b[MX];
bool dfs(const int& c) {
  b[c] = true;
  q.push(v[c]);
  if (q.size() == n) {
    while (!q.empty()) {
      printf("%lld ", q.front());
      q.pop();
    }

    return true;
  }

  for (int i = 0; i < n; i++) {
    if (i == c || b[i]) continue;
    if (v[c] * 2 != v[i] && ((v[c] % 3) || v[c] / 3 != v[i])) continue;
    if (dfs(i)) return true;
  }
  q.pop();

  return b[c] = false;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%lld", &v[i]);
  for (int i = 0; i < n; i++)
    if (dfs(i)) break;
}