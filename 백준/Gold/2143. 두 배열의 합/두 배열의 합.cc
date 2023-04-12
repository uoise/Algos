#include <cstdio>
#include <unordered_map>

constexpr int MX = 1e3;
std::unordered_map<int, int> mv[2];
int t, n, s, v[MX];
long long r;
void inp(int o) {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  for (int i = 0; i < n; i++) {
    s = 0;
    for (int j = i; j < n; j++) {
      s += v[j];
      auto fnd = mv[o].find(s);
      if (fnd == mv[o].end())
        mv[o].insert({s, 1});
      else
        fnd->second++;
    }
  }
}

int main() {
  scanf("%d", &t);
  inp(0);
  inp(1);
  for (auto it = mv[0].begin(); it != mv[0].end(); it++) {
    auto fnd = mv[1].find(t - it->first);
    if (fnd == mv[1].end()) continue;
    r += (long long)fnd->second * (long long)it->second;
  }
  printf("%lld", r);
}