#include <cstdio>
#include <unordered_set>
#include <vector>

std::unordered_set<long long> s;
std::vector<long long> r;
int main() {
  long long x, n;
  scanf("%lld %lld", &x, &n);
  while (n-- > 0) {
    x = (x & 1 ? x << 1 : x >> 1) ^ 6;
    if (s.count(x)) break;
    s.insert(x);
  }

  s.clear();
  while (n-- > 0) {
    x = (x & 1 ? x << 1 : x >> 1) ^ 6LL;
    if (s.count(x)) break;
    s.insert(x);
    r.push_back(x);
  }
  if (n > 0) x = r[(r.size() + n) % r.size()];

  printf("%lld", x);
}