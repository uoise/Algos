#include <algorithm>
#include <cstdio>
#include <stack>
#include <vector>

using namespace std;
using iar = vector<int>;
constexpr int MX = 1e4 + 1;

vector<iar> vv, rv;
stack<int> sk;
int bv[MX], sq, rr;
int dfs(const int cur) {
  bv[cur] = ++sq;
  sk.push(cur);

  int prt = bv[cur];
  for (const auto& nxt : vv[cur])
    if (!bv[nxt])
      prt = min(prt, dfs(nxt));
    else if (bv[nxt] > 0)
      prt = min(prt, bv[nxt]);

  if (prt == bv[cur]) {
    iar tv;
    while (!sk.empty()) {
      int t = sk.top();
      sk.pop();
      bv[t] = -cur;
      tv.push_back(t);
      if (t == cur) break;
    }
    sort(tv.begin(), tv.end());
    rv[tv[0]] = tv;
    rr++;
  }

  return prt;
}

void sol() {
  int v, e, x, y;
  scanf("%d %d", &v, &e);
  vv.assign(v + 1, iar());
  rv.assign(v + 1, iar());
  for (int i = 0; i < e; i++) {
    scanf("%d %d", &x, &y);
    vv[x].push_back(y);
  }

  for (int i = 1; i <= v; i++)
    if (!bv[i]) dfs(i);

  printf("%d\n", rr);
  for (const auto& v : rv)
    if (v.size()) {
      for (const auto& i : v) printf("%d ", i);
      printf("-1\n");
    }
}

int main() { sol(); }