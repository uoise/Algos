#include <algorithm>
#include <cstdio>

using namespace std;

int n, v[2000], r, x;
pair<int, int> s[2000 * 2000];
bool sol(const int i) {
  auto b = lower_bound(s, s + x, make_pair(v[i], 0));
  auto e = lower_bound(s, s + x, make_pair(v[i] + 1, 0));
  for (b; b != e; b++)
    if (b->second / n != i && b->second % n != i) return 1;
  return 0;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++) s[x++] = {v[i] + v[j], i * n + j};
  sort(s, s + x);
  for (int i = 0; i < n; i++)
    if (sol(i)) ++r;
  printf("%d", r);
}