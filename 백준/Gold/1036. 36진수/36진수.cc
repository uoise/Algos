#include <algorithm>
#include <cstdio>
#include <cstring>

constexpr int ML = 60, MN = 36;
int cti(const char& c) {
  if (c >= '0' && c <= '9') return c - '0';
  if (c >= 'A' && c <= 'Z') return c - 'A' + 10;
  return 0;
}

char itc(const int& i) {
  if (i < 10) return '0' + i;
  return 'A' + i - 10;
}

struct hs {
  int s[ML], l;
  void operator+=(const hs& o) {
    int c = 0, t = 0;
    for (int i = 0; i < ML; i++) {
      t = s[i] + o.s[i] + c;
      s[i] = t % MN, c = t / MN;
    }
  }

  bool operator<(const hs& o) const {
    if (l != o.l) return l < o.l;
    for (int i = l - 1; i >= 0; i--)
      if (s[i] != o.s[i]) return s[i] < o.s[i];
    return 0;
  }
};

hs res, hv[MN];
void input() {
  hs c;
  char inp[51];
  int n, len;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", inp);
    len = strlen(inp);
    memset(c.s, 0, sizeof c.s);
    for (int j = 0; j < len; j++) {
      int pos = len - 1 - j, val = cti(inp[j]);
      c.s[pos] = val, hv[val].s[pos] += 35 - val;
    }
    res += c;
  }
}

void sol() {
  int p = MN, k;
  for (int i = 0; i < MN; i++) {
    auto& c = hv[i];
    for (int j = 0; j < ML - 1; j++) {
      c.s[j + 1] += c.s[j] / MN;
      c.s[j] %= MN;
      if (c.s[j]) c.l = j + 1;
    }
  }
  std::sort(hv, hv + MN);
  scanf("%d", &k);
  while (k--) res += hv[--p];

  p = 0;
  for (int i = ML - 1; i >= 0; i--) {
    if (res.s[i] && !p) p = 1;
    if (p) printf("%c", itc(res.s[i]));
  }
  if (!p) printf("0");
}

int main() {
  input();
  sol();
}