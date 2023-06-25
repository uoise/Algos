#include <cstdio>

int n, c, r, s;
bool v[51][51];
void dfs(const int& cur) {
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (!v[cur][i]) continue;
    dfs(i);
    ++cnt;
  }
  if (!cnt) ++r;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &c);
    if (c == -1)
      s = i;
    else
      v[c][i] = 1;
  }
  scanf("%d", &c);
  if (c == s) r = -1;
  for (int i = 0; i < n; i++) v[c][i] = v[i][c] = 0;
  dfs(s);
  printf("%d", r);
}