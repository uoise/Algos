#include <cstdio>
constexpr char o[] = {' ', '+', '-'};
int n;
char s[20] = {'1',};
void btr(int c) {
  if (c == n) {
    int r = 0, v = 0, p = 1;
    for (int i = 0; i < n * 2 - 1; i++) {
      if (s[i] == ' ') continue;
      if (s[i] < '0') r += v * p, v = 0, p = s[i] == '+' ? 1 : -1;
      else v = v * 10 + s[i] - '0';
    }
    r += v * p;
    if (!r) printf("%s\n", s);
    return;
  }

  for (int i = 0; i < 3; i++) {
    s[c * 2 - 1] = o[i], s[c * 2] = '0' + c + 1;
    btr(c + 1);
  }
}

void sol() {
  scanf("%d", &n);
  s[0] = '1';
  btr(1);
  printf("\n");
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) sol();
}