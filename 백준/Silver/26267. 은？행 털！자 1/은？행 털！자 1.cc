#include <algorithm>
#include <cstdio>
#include <unordered_map>
std::unordered_map<int, long long> um;
int n, x, t, c;
long long r;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", &x, &t, &c);
    auto it = um.find(t - x);
    if (it == um.end())
      um.insert({t - x, c});
    else
      it->second += c;
  }
  for (const auto& it : um) r = it.second > r ? it.second : r;
  printf("%lld", r);
}