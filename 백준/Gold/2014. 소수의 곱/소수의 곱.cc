#include <cstdio>
#include <queue>

constexpr long long MX = 1LL << 31;
std::priority_queue<long long> q;
long long l, t;
int k, n, p[101];
int main() {
  scanf("%d %d", &k, &n);
  for (int i = 0; i < k; i++) {
    scanf("%d", &p[i]);
    q.push(-p[i]);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < k; j++) {
      l = -q.top();
      t = l * p[j];
      if (t >= MX) break;
      q.push(-t);
      if (!(l % p[j])) break;
    }
    q.pop();
  }
  printf("%lld", l);
}