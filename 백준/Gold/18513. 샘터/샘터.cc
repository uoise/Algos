#include <cstdio>
#include <queue>
#include <unordered_set>

std::unordered_set<int> s;
std::queue<std::pair<int, long long>> q;
int n, k;
long long r;
long long sol() {
  scanf("%d %d", &n, &k);
  while (n--) {
    int x;
    scanf("%d", &x);
    s.insert(x), q.push({x, 1});
  }

  while (q.size()) {
    auto [c, d] = q.front();
    q.pop();
    for (int i = -1; i < 2; i += 2) {
      int a = c + i;
      if (s.count(a)) continue;
      s.insert(a);
      q.push({a, d + 1});
      r += d;
      if (!--k) return r;
    }
  }

  return -1;
}

int main() { printf("%lld", sol()); }