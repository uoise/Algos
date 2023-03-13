#include <cstdio>
#include <cstring>
#include <unordered_map>

constexpr int MX = 1e5 + 1;

std::unordered_map<int, int> mp;
int T, n, r, dep, vv[MX];
bool bv[MX];
void dfs(const int& x) {
  bv[x] = 1;
  mp.insert({x, ++dep});
  int& nxt = vv[x];
  if (!bv[nxt]) {
    dfs(nxt);
  } else {
    if (mp.find(nxt) != mp.end()) r -= (mp[x] - mp[nxt] + 1);
    mp.clear();
  }
}

int sol() {
  r = n;
  for (int i = 1; i <= n; i++)
    if (!bv[i]) {
      dep = 0;
      dfs(i);
    }
  return r;
}

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &vv[i]);
    printf("%d\n", sol());
    memset(bv, 0, sizeof bv);
  }
}