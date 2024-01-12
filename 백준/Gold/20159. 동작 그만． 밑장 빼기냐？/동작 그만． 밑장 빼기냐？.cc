#include <algorithm>
#include <cstdio>
using namespace std;
constexpr int MX = 1e5 + 1;
int n, v[MX], r;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    if (i > 1) v[i] += v[i - 2];
  }
  r = max(v[n - 1], v[n - 2]);
  for (int i = 2; i < n; i++) r = max(r, i % 2 ? v[i - 1] + v[n - 3] - v[i - 2]
                                               : v[i - 2] + v[n - 1] - v[i - 1]);
  printf("%d", r);
}