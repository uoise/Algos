#include <cstdio>
#include <unordered_map>

std::unordered_map<int, int> map;
int n, s, t, v[40];
long long r;
void dfs(const int d) {
  if (d == n / 2) {
    auto fnd = map.find(t);
    if (fnd == map.end())
      map.insert({t, 1});
    else
      fnd->second++;
    return;
  }
  dfs(d + 1);
  t += v[d];
  dfs(d + 1);
  t -= v[d];
}

void clc(const int d) {
  if (d == n) {
    auto fnd = map.find(s - t);
    if (fnd != map.end()) r += fnd->second;
    return;
  }
  clc(d + 1);
  t += v[d];
  clc(d + 1);
  t -= v[d];
}

int main() {
  scanf("%d %d", &n, &s);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  dfs(0);
  clc(n / 2);
  printf("%lld", s ? r : r - 1);
}