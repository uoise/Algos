#include <cstdio>
#include <unordered_set>

void sol() {
  int n, m, x;
  std::unordered_set<int> s;
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &x);
    s.insert(x);
  }
  scanf("%d", &m);
  while (m--) {
    scanf("%d", &x);
    printf("%d\n", s.count(x) ? 1 : 0);
  }
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) sol();
}