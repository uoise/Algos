#include <algorithm>
#include <cstdio>
#include <string>
#include <unordered_set>

char c[1001][1001];
std::string t[1001];
std::unordered_set<std::string> us;
int y, x, r;
bool sol(const int& l) {
  int b;
  us.clear();
  for (int i = 0; i < x; i++) {
    b = us.size();
    us.insert(t[i].substr(l, y - l));
    if (b == us.size()) return false;
  }
  return true;
}

int main() {
  scanf("%d %d", &y, &x);
  for (int i = 0; i < y; i++) scanf("%s", c[i]);
  for (int i = 0; i < x; i++)
    for (int j = 0; j < y; j++) t[i] += c[j][i];

  int s = 0, e = y;
  while (s <= e) {
    int m = (s + e) / 2;
    if (sol(m)) {
      r = std::max(r, m);
      s = m + 1;
    } else {
      e = m - 1;
    }
  }
  printf("%d", r);
}