#include <algorithm>
#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>

constexpr int MX = 1e4 + 1;
std::vector<int> vv[MX];
std::stack<int> stk;
bool bv[MX];
int cv[MX];
int clc(int c) {
  int r = 1;
  bv[c] = 1;
  stk.push(c);
  while (!stk.empty()) {
    c = stk.top();
    stk.pop();
    for (const int& a : vv[c]) {
      if (bv[a]) continue;
      bv[a] = 1, ++r;
      stk.push(a);
    }
  }
  memset(bv, 0, sizeof bv);
  return r;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  while (m--) {
    int s, e;
    scanf("%d %d", &e, &s);
    vv[s].push_back(e);
  }

  m = 0;
  for (int i = 1; i <= n; i++) m = std::max(m, cv[i] = clc(i));
  for (int i = 1; i <= n; i++) if (cv[i] == m) printf("%d ", i);
}