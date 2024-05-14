#include <algorithm>
#include <bitset>
#include <cstdio>

std::bitset<50> g[10];
std::bitset<10> v[50];
int N, M, r;
void btr(int c, int s) {
  if (c == N) {
    r = std::min(r, s);
    return;
  }

  bool t = 1;
  for (int m = 0; t && m < M; m++) {
    if (v[m].none()) continue;
    v[m][c] = 0;
    t = v[m].count();
  }
  if (t) btr(c + 1, s - 1);
  for (int m = 0; m < M; m++) v[m][c] = g[c][m];
  btr(c + 1, s);
}

int sol() {
  int x = M;
  for (int m = 0; m < M; m++) x -= v[m].none();
  if (!x) return -1;
  r = N;
  btr(0, N);
  return r;
}

int main() {
  scanf("%d %d", &N, &M);
  char s[51];
  for (int n = 0; n < N; n++) {
    scanf("%s %s", s, s);
    for (int m = 0; m < M; m++) v[m][n] = g[n][m] = s[m] == 'Y';
  }
  printf("%d", sol());
}