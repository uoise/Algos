#include <cstdio>
#include <set>
#include <string>

constexpr int MN = 1003002;
std::set<int> s;
bool p[MN];
void clc(const int x) {
  std::string c = std::to_string(x);
  for (int i = 0; i < c.size(); i++) if (c[i] != c[c.size() - i - 1]) return;
  s.insert(x);
}

int main() {
  for (int i = 2; i < MN; i++) {
    if (p[i]) continue;
    clc(i);
    for (int j = 2 * i; j < MN; j += i) p[j] = 1;
  }
  int n;
  scanf("%d", &n);
  printf("%d", *s.lower_bound(n));
}