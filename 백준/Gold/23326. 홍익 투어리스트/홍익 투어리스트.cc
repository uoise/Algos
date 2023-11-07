#include <cstdio>
#include <set>

std::set<int> s;
int main() {
  int n, q, c = 0, x, o;
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    if (x) s.insert(i);
  }

  while (q--) {
    scanf("%d", &x);
    if (x == 3) {
      auto r = s.lower_bound(c);
      printf("%d\n", s.empty()      ? -1
                     : r == s.end() ? *s.begin() + n - c
                                    : *r - c);
      continue;
    }

    scanf("%d", &o);
    if (x == 1) {
      if (s.find(--o) == s.end())
        s.insert(o);
      else
        s.erase(o);
    } else {
      c = (c + o) % n;
    }
  }
}