#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>

constexpr int MN = 52, SS = 0, EE = 25, INF = 1001;
std::queue<int> q;
int cap[MN][MN], flw[MN][MN], prt[MN];
int sol() {
  int r = 0;
  while (1) {
    memset(prt, -1, sizeof prt);
    prt[SS] = SS;
    q.push(SS);
    while (!q.empty()) {
      int c = q.front();
      q.pop();
      for (int a = 0; a < MN; a++) {
        if (cap[c][a] <= flw[c][a] || prt[a] != -1) continue;
        prt[a] = c;
        q.push(a);
        if (a == EE) break;
      }
    }

    if (prt[EE] == -1) break;
    int c = EE, mf = INF;
    while (c != SS) {
      int a = prt[c];
      int rst = cap[a][c] - flw[a][c];
      if (rst > 0) mf = std::min(mf, rst);
      c = prt[c];
    }
    c = EE;
    while (c != SS) {
      int a = prt[c];
      flw[a][c] += mf, flw[c][a] -= mf;
      c = prt[c];
    }
    r += mf;
  }

  return r;
}

int main() {
  char a, b;
  int n, s, e, w;
  scanf("%d\n", &n);
  while (n--) {
    scanf("%c %c %d\n", &a, &b, &w);
    s = (a - 'a' < 0) ? (a - 'A') : (a - 'a' + 26);
    e = (b - 'a' < 0) ? (b - 'A') : (b - 'a' + 26);
    cap[s][e] += w, cap[e][s] += w;
  }
  printf("%d", sol());
}