#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>

constexpr int MX = 3e5 + 1;

std::priority_queue<std::pair<int, int>> q;
std::vector<int> ev[MX];
long long r;
int n, vv[MX];
int main() {
  int p;
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    scanf("%d", &p);
    ev[p].push_back(i);
  }
  for (int i = 1; i <= n; i++) scanf("%d", &vv[i]);

  q.push({vv[1], 1});
  while (n--) {
    p = q.top().second, r += q.top().first;
    q.pop();
    printf("%lld\n", r);
    for (const int& c : ev[p]) q.push({vv[c], c});
  }
}