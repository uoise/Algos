#include <cstdio>
#include <cstring>
#include <queue>

constexpr int MX = 1e4;
bool pv[MX];
int bv[MX];
std::queue<int> q;
void fnd(int s, const int& w, const int& pos) {
  s -= (pos == 1 ? s : s / pos) % 10 * pos;
  for (int i = 0; i < 10; i++) {
    if (pos == 1000 && !i) continue;
    s += i * pos;
    if (!pv[s] && !bv[s]) {
      bv[s] = w;
      q.push(s);
    }
    s -= i * pos;
  }
}

int sol(int s, const int& e) {
  bv[s] = 1;
  q.push(s);
  while (!q.empty()) {
    s = q.front();
    q.pop();
    if (s == e) return bv[s] - 1;
    for (int i = 1; i < MX; i *= 10) fnd(s, bv[s] + 1, i);
  }

  return -1;
}

int main() {
  int T, s, e, r;
  bv[0] = bv[1] = 1;
  for (int i = 2; i < MX; i++) {
    if (pv[i]) continue;
    for (int j = 2; i * j < MX; j++) pv[i * j] = 1;
  }
  scanf("%d", &T);
  while (T--) {
    scanf("%d %d", &s, &e);
    r = sol(s, e);
    if (r < 0)
      printf("Impossible\n");
    else
    printf("%d\n", r);
    memset(bv, 0, sizeof bv);
    while (!q.empty()) q.pop();
  }
}