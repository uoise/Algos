#include <cstdio>
#include <vector>

constexpr int MX = 1e5 + 1;
std::vector<int> vv[MX], iv;
int n, bv[MX];
bool sol() {
  int l = 1, d = 1;
  bv[1] = l;
  for (const int& c : iv) {
    if (bv[c] < l) return 0;
    l = bv[c];
    bv[c] = -1;
    ++d;
    for (const int& a : vv[c]) bv[a] = bv[a] ? bv[a] : d;
  }

  return 1;
}

int main() {
  scanf("%d", &n);
  iv.assign(n, 0);
  for (int i = 1; i < n; i++) {
    int s, e;
    scanf("%d %d", &s, &e);
    vv[s].push_back(e);
    vv[e].push_back(s);
  }
  for (int& i : iv) scanf("%d", &i);
  printf("%d", sol());
}