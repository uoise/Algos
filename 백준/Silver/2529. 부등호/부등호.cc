#include <iostream>

bool ov[10], bv[10], rb;
char rs[11];
int n;
void btr(int c, bool p) {
  if (c == n + 1) {
    rb = 1;
    printf("%s\n", rs);
    return;
  }

  for (int i = (p ? 9 : 0); !rb && i != (p ? -1 : 10); i += (p ? -1 : 1)) {
    if (bv[i]) continue;
    if (ov[c - 1] && ((rs[c - 1] - '0') < i)) continue;
    if (!ov[c - 1] && ((rs[c - 1] - '0') > i)) continue;
    bv[i] = 1, rs[c] = '0' + i;
    btr(c + 1, p);
    bv[i] = 0;
  }
}

int main() {
  std::cin.tie(0)->sync_with_stdio(0);
  std::cin >> n;
  char c;
  for (int i = 0; i < n; i++) {
    std::cin >> c;
    ov[i] = c == '>';
  }

  btr(0, 1);
  rb = 0;
  btr(0, 0);
}