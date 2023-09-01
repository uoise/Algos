#include <cstdio>

constexpr int MX = 1e5 + 1;

long long r;
bool b[MX];
int n, v[MX], e = 1;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  b[v[0]] = 1;
  for (int s = 0; s < n; s++) {
    while (e < n && !b[v[e]]) b[v[e++]] = true;
    r += e - s;
    b[v[s]] = 0;
  }

  printf("%lld", r);
}