#include <bitset>
#include <cstdio>
#include <string>

constexpr std::bitset<7> sv[10] = {0b1111110, 0b0110000, 0b1101101, 0b1111001,
                                   0b0110011, 0b1011011, 0b1011111, 0b1110000,
                                   0b1111111, 0b1111011};
std::string c, a;
int n, k, p;
bool clc(int tgt) {
  int cnt = 0;
  a = std::to_string(tgt);
  while (a.length() < k) a = '0' + a;
  for (int i = 0; i < k; i++) cnt += (sv[c[i] - '0'] ^ sv[a[i] - '0']).count();
  return p >= cnt;
}

int sol() {
  int x, r = -1;
  scanf("%d %d %d %d", &n, &k, &p, &x);
  c = std::to_string(x);
  while (c.length() < k) c = '0' + c;
  for (int i = 1; i <= n; i++) r += clc(i);
  return r;
}

int main() { printf("%d", sol()); }