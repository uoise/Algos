#include <cstdio>
#include <set>

std::multiset<int> m;
int sol() {
  if (m.empty()) return 0;
  int r = 1;
  auto it = m.begin();
  while (1) {
    it = m.lower_bound((*it) * 2);
    if (it == m.end()) return r;
    ++r;
  }
  return 0;
}

int main() {
  int Q, o, s;
  scanf("%d", &Q);
  while (Q--) {
    scanf("%d", &o);
    if (o == 3) {
      printf("%d\n", sol());
    } else {
      scanf("%d", &s);
      if (o == 1)
        m.insert(s);
      else if (m.count(s))
        m.erase(m.find(s));
    }
  }
}