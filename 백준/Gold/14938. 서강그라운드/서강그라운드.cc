#include <cstdio>
#include <cstring>
#include <queue>

int n, m, r, b, e, l, res, vv[100], dv[100][100], cv[100];
std::priority_queue<std::pair<int, int>> pq;
void djs(int cur) {
  memset(cv, 0x3f, sizeof cv);
  cv[cur] = 0;
  pq.push({-cv[cur], cur});
  while (!pq.empty()) {
    b = pq.top().second, l = -pq.top().first;
    pq.pop();
    for (int i = 0; i < n; i++) {
      if (cv[i] > dv[b][i] + l && m >= dv[b][i] + l) {
        cv[i] = dv[b][i] + l;
        pq.push({-cv[i], i});
      }
    }
  }
  e = 0;
  for (int i = 0; i < n; i++) if (cv[i] <= m) e += vv[i];
  if (res < e) res = e;
}

int main() {
  memset(dv, 0x3f, sizeof dv);
  scanf("%d %d %d", &n, &m, &r);
  for (int i = 0; i < n; i++) scanf("%d", &vv[i]);
  for (int i = 0; i < r; i++) {
    scanf("%d %d %d", &b, &e, &l);
    dv[b - 1][e - 1] = dv[e - 1][b - 1] = l;
  }
  for (int i = 0; i < n; i++) djs(i);
  printf("%d", res);
}