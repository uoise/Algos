#include <cstdio>
#include <unordered_map>

std::unordered_map<long long, long long> m;
int n;
long long k, v[200001], r;
int main() {
  scanf("%d %lld", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &v[i]);
    v[i] += v[i - 1];
  }
  for (int i = 1; i <= n; i++) {
    if (v[i] == k) ++r;
    r += m[v[i] - k];
    ++m[v[i]];
  }
  printf("%lld", r);
}