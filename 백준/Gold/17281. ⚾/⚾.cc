#include <algorithm>
#include <cstdio>
#include <cstring>

bool base[3], bv[9];
int n, iv[51][9], batter[9], cur, res;
int inning(int inn) {
  int out = 3, point = 0;
  while (out) {
    int &hit = iv[inn][batter[cur]];
    cur = (cur + 1) % 9;
    if (!hit) {
      --out;
      continue;
    }
    for (int i = 2; i >= 0; i--) {
      if (!base[i]) continue;
      base[i] = 0;
      int nxt = i + hit;
      if (nxt >= 3)
        ++point;
      else
        base[nxt] = 1;
    }
    if (hit == 4)
      ++point;
    else
      base[hit - 1] = 1;
  }
  memset(base, 0, sizeof base);
  return point;
}

void game() {
  int point = 0;
  for (int i = 0; i < n; i++) point += inning(i);
  res = std::max(res, point), cur = 0;
}

void btr(int c) {
  if (!c) {
    game();
    return;
  }

  if (c == 4) {
    btr(c - 1);
    return;
  }

  for (int i = 1; i < 9; i++) {
    if (bv[i]) continue;
    batter[c - 1] = i, bv[i] = 1;
    btr(c - 1);
    bv[i] = 0;
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < 9; j++) scanf("%d", &iv[i][j]);
  btr(9);
  printf("%d", res);
}