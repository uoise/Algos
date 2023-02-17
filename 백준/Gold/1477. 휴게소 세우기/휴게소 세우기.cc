#include <algorithm>
#include <cstdio>

using namespace std;

int n, m, v[52], r, s, t;
bool clc(const int& len) {
  s = 0;
  for (int i = 1; i < n + 2; i++) {
    t = v[i] - v[i - 1];
    if (t >= len) s += (t / len - (t % len ? 0 : 1));
  }
  return m >= s;
}

int sol() {
  int b = 1, e = r, v;
  while (b <= e) {
    v = (b + e) / 2;
    if (clc(v))
      r = v, e = v - 1;
    else
      b = v + 1;
  }
  return r;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n + 1; i++) scanf("%d", &v[i]);
  sort(v, v + n + 2);
  for (int i = 1; i < n + 2; i++) r = max(r, v[i] - v[i - 1]);
  printf("%d", sol());
}