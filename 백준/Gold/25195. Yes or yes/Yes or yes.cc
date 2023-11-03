#include <cstdio>
#include <vector>

bool r, vv[100001];
int n;
std::vector<int> ev[100001];
void dfs(int c) {
  if (vv[c]) return;
  if (ev[c].empty()) {
    r = 1;
    return;
  }

  for (const int& a : ev[c]) if (!vv[a]) dfs(a);
}

int main() {
  int m, s, e;
  scanf("%d %d", &n, &m);
  while (m--) {
    scanf("%d %d", &s, &e);
    ev[s].push_back(e);
  }
  scanf("%d", &m);
  while (m--) {
    scanf("%d", &s);
    vv[s] = 1;
  }
  dfs(1);
  printf("%s", r ? "yes" : "Yes");
}