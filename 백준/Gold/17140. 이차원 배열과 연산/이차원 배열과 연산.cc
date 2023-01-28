#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

pair<int, int> vv[101];
int r, c, k, va[100][100], t;
int yz = 3, xz = 3, idx, tmp, vt[100][100], bv[101];
void rst() {
  for (int i = 0; i < 101; i++) vv[i] = {0, 0};
  memset(bv, 0, sizeof bv);
}

void smv() {
  idx = 0;
  for (int i = 1; i < 101; i++)
    if (bv[i]) vv[idx++] = {bv[i], i};
  sort(vv, vv + idx);
  if (tmp < idx * 2) tmp = idx * 2;
  if (tmp > 100) tmp = 100;
}

void clc() {
  tmp = 0;
  for (int x = 0; x < xz; x++) {
    rst();
    for (int y = 0; y < yz; y++) ++bv[va[y][x]];
    smv();
    for (int y = 0; y < idx; y++)
      vt[y * 2][x] = vv[y].second, vt[y * 2 + 1][x] = vv[y].first;
  }
  yz = tmp;
}

void clr() {
  tmp = 0;
  for (int y = 0; y < yz; y++) {
    rst();
    for (int x = 0; x < xz; x++) ++bv[va[y][x]];
    smv();
    for (int x = 0; x < idx; x++)
      vt[y][x * 2] = vv[x].second, vt[y][x * 2 + 1] = vv[x].first;
  }
  xz = tmp;
}

int main() {
  scanf("%d %d %d", &r, &c, &k);
  --r, --c;
  for (int y = 0; y < yz; y++)
    for (int x = 0; x < xz; x++) scanf("%d", &va[y][x]);
  while (va[r][c] != k && t++ < 101) {
    if (xz > yz)
      clc();
    else
      clr();
    memcpy(va, vt, sizeof vt);
    memset(vt, 0, sizeof vt);
  }
  printf("%d", t > 100 ? -1 : t);
}