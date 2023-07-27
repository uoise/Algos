#include <cstdio>

int n, m, s, e, r;
bool v[501][501];
bool sol(const int& c) {
  for (int i = 0; i < n; i++) {
    if (c == i) continue;
    if (!v[c][i] && !v[i][c]) return 0;
  }
  return 1;
}

int main() {
  scanf("%d %d", &n, &m);
  while (m--) {
    scanf("%d %d", &s, &e);
    v[s - 1][e - 1] = 1;
  }

  for (int i = 0; i < n; i++)
    for (s = 0; s < n; s++)
      for (e = 0; e < n; e++) v[s][e] = v[s][e] || (v[s][i] && v[i][e]);

  for (s = 0; s < n; s++) if (sol(s)) ++r;
  printf("%d", r);
}