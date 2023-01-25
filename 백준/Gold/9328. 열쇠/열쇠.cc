#include <cctype>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

constexpr int xx[] = {1, 0, -1, 0}, yy[] = {0, 1, 0, -1};
int n, m, r;
bool bv[100][100], cv[26];
char vv[100][101], fv[27];
queue<pair<int, int>> q, fq[26];
int valid(const int& y, const int& x) {
  if (y < 0 || y >= n || x < 0 || x >= m) return 0;
  char& c = vv[y][x];
  if (bv[y][x] || c == '*') return 0;
  if (isupper(c)) {
    if (!cv[c - 'A']) {
      fq[c - 'A'].push({y, x});
      bv[y][x] = 1;
      return 0;
    }
  }
  if (c != '.') {
    if (c == '$')
      ++r;
    else if (islower(c))
      cv[c - 'a'] = 1;
    c = '.';
  }
  return 1;
}

void qpush(const int& y, const int& x) {
  bv[y][x] = 1;
  q.push({y, x});
}

void bfs() {
  int y, x, ny, nx;
  while (!q.empty()) {
    y = q.front().first, x = q.front().second;
    // printf("(%d, %d)\n", y, x);
    q.pop();
    for (int i = 0; i < 4; i++) {
      ny = y + yy[i], nx = x + xx[i];
      if (!valid(ny, nx)) continue;
      bv[ny][nx] = 1;
      q.push({ny, nx});
    }
  }
}

int sol() {
  r = 0;
  for (int i = 0; i < n; i++) {
    if (valid(i, 0)) qpush(i, 0);
    if (valid(i, m - 1)) qpush(i, m - 1);
  }
  for (int i = 0; i < m; i++) {
    if (valid(0, i)) qpush(0, i);
    if (valid(n - 1, i)) qpush(n - 1, i);
  }

  while (!q.empty()) {
    bfs();
    for (int i = 0; i < 26; i++) {
      if (cv[i])
        while (!fq[i].empty()) {
          qpush(fq[i].front().first, fq[i].front().second);
          fq[i].pop();
        }
    }
  }
  memset(bv, 0, sizeof bv);
  memset(cv, 0, sizeof cv);
  for (int i = 0; i < 26; i++)
    while (!fq[i].empty()) fq[i].pop();
  return r;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", vv[i]);
    scanf("%s", fv);
    for (int i = 0; isalpha(fv[i]); i++) cv[fv[i] - 'a'] = 1;
    printf("%d\n", sol());
  }
}
