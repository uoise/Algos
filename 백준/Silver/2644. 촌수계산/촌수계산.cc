#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int>> vv(101, vector<int>());
int n, x, y, m, f, c, r = -1;
bool bv[101];
void dfs(int p, int d) {
  bv[p] = 1;
  for (const auto& i : vv[p]) {
    if (i == y) {
      r = d;
      return;
    } else if (!bv[i] && r < 0) {
      dfs(i, d + 1);
    }
  }
}

int main() {
  scanf("%d\n %d %d\n %d", &n, &x, &y, &m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d", &f, &c);
    vv[f].push_back(c);
    vv[c].push_back(f);
  }
  dfs(x, 1);
  printf("%d", r);
}