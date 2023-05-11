#include <cstdio>
#include <cstring>
#include <queue>

constexpr int xx[] = {1, 0, -1, 0}, yy[] = {0, 1, 0, -1};
std::queue<std::pair<int, int>> q;
int r;
bool bv[25], cv[25], tv[25];
bool rch() {
  memset(tv, 0, sizeof tv);
  while (!q.empty()) q.pop();
  int y, x;
  for (int i = 0; i < 25; i++) {
    if (bv[i]) {
      q.push({i / 5, i % 5});
      tv[i] = true;
      break;
    }
  }
  int cnt = 1;
  while (!q.empty()) {
    y = q.front().first, x = q.front().second;
    q.pop();
    for (int d = 0; d < 4; d++) {
      int ny = y + yy[d], nx = x + xx[d];
      if (ny < 0 || ny > 4 || nx < 0 || nx > 4 || tv[ny * 5 + nx] ||
          !bv[ny * 5 + nx])
        continue;
      cnt++;
      tv[ny * 5 + nx] = 1;
      q.push({ny, nx});
    }
  }
  return cnt == 7;
}
void dfs(const int& pos, const int& dep, const int& cnt) {
  if (dep + cnt < 4) return;
  if (!dep) {
    if (rch()) ++r;
    return;
  }

  for (int i = pos; i < 25; i++) {
    bv[i] = 1;
    dfs(i + 1, dep - 1, cnt + (cv[i] ? 1 : 0));
    bv[i] = 0;
  }
}

int main() {
  char s[6];
  for (int y = 0; y < 5; y++) {
    scanf("%s", s);
    for (int x = 0; x < 5; x++) cv[y * 5 + x] = (s[x] == 'S' ? true : false);
  }

  dfs(0, 7, 0);
  printf("%d", r);
}