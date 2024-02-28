#include <iostream>

bool ov[10], bv[10], rb;
char rs[11];
int n;
void btr(int c) {
  if (c == n + 1) {
    rb = 1;
    printf("%s\n", rs);
    return;
  }

  for (int i = 9; !rb && i >= 0; i--) {
    if (bv[i]) continue;
    if (ov[c - 1] && ((rs[c - 1] - '0') < i)) continue;
    if (!ov[c - 1] && ((rs[c - 1] - '0') > i)) continue;
    bv[i] = 1, rs[c] = '0' + i;
    btr(c + 1);
    bv[i] = 0;
  }
}

void rtr(int c) {
  if (c == n + 1) {
    rb = 1;
    printf("%s\n", rs);
    return;
  }

  for (int i = 0; !rb && i < 10; i++) {
    if (bv[i]) continue;
    if (ov[c - 1] && ((rs[c - 1] - '0') < i)) continue;
    if (!ov[c - 1] && ((rs[c - 1] - '0') > i)) continue;
    bv[i] = 1, rs[c] = '0' + i;
    rtr(c + 1);
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

  for (int i = 9; !rb && i >= 0; i--) {
    bv[i] = 1, rs[0] = '0' + i;
    btr(1);
    bv[i] = 0;
  }
  
  rb = 0;
  for (int i = 0; !rb && i < 10; i++) {
    bv[i] = 1, rs[0] = '0' + i;
    rtr(1);
    bv[i] = 0;
  }
}