#include <algorithm>
#include <cstdio>
#include <queue>

struct ti {
  int a, b, c;
  int& operator[](int i) {
    if (i == 1) return b;
    if (i == 2) return c;
    return a;
  }
};

std::queue<ti> q;
bool bv[201][201][201], r[201];
ti o, c, a;
int main() {
  scanf("%d %d %d", &o[0], &o[1], &o[2]);
  bv[o[0]][o[1]][o[2]] = r[o[2]] = 1;
  q.push({0, 0, o[2]});
  while (!q.empty()) {
    c = q.front();
    q.pop();
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        if (i == j || !c[i] || c[j] == o[j]) continue;
        a[j] = std::min(o[j], c[i] + c[j]);
        a[i] = c[i] + c[j] - a[j];
        a[3 - i - j] = c[3 - i - j];
        if (bv[a[0]][a[1]][a[2]]) continue;
        if (!a[0]) r[a[2]] = 1;
        bv[a[0]][a[1]][a[2]] = 1;
        q.push(a);
      }
    }
  }
  for (int i = 0; i < 201; i++) if (r[i]) printf("%d ", i);
}