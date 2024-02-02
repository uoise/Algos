#include <cstdio>
#include <string>

constexpr char o[] = {' ', '+', '-'};
int n;
void btr(int c, std::string s) {
  if (c == n) {
    int r = 0, v = 0, p = 1;
    for (const char c : s) {
      if (c == ' ') continue;
      if (c == '+' || c == '-') r += v * p, v = 0, p = c == '+' ? 1 : -1;
      else v = v * 10 + c - '0';
    }
    r += v * p;
    if (!r) printf("%s\n", s.c_str());
    return;
  }

  for (int i = 0; i < 3; i++) btr(c + 1, s + o[i] + (char)('0' + c + 1));
}

void sol() {
  scanf("%d", &n);
  btr(1, "1");
  printf("\n");
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) sol();
}