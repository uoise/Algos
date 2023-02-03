#include <algorithm>
#include <cstdio>
#include <set>

using namespace std;

multiset<int> s;
int n, m, c[50], x, r;
int sol() {
  while (!s.empty()) {
    x = 0, ++r;
    for (int i = 0; i < n; i++) {
      auto f = s.upper_bound(c[i]);
      if (f == s.begin()) continue;
      s.erase(--f);
      ++x;
    }
    if (!x) return -1;
  }
  return r;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &c[i]);
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
    scanf("%d", &x);
    s.insert(x);
  }
  printf("%d", sol());
}