#include <cstdio>
#include <unordered_map>
#include <unordered_set>

std::unordered_map<int, long long> m;
std::unordered_map<int, std::unordered_set<int>> s;
long long r;
int n, v[2001], t;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      auto& t = s[v[i] + v[j]];
      if (t.find(i) != t.end() || t.find(j) != t.end()) continue;
      t.insert(i);
      t.insert(j);
      m[v[i] + v[j]] += 1LL * v[i] * v[j];
    }
  }
  for (const auto& p : m) if (r < p.second) r = p.second;
  printf("%lld", r);
}