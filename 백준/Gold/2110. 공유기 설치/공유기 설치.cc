#include <algorithm>
#include <cstdio>
int n, c, v[200001], r, l;

bool clc(const int& len) {
  r = 1, l = 0;
  for (int i = 1; i < n; i++)
    if (v[i] - v[l] >= len) ++r, l = i;
  return r >= c;
}

int sol() {
  int beg = 0, end = v[n - 1], mid, res;
  while (beg <= end) {
    mid = (beg + end) / 2;
    if (clc(mid)) {
      res = mid;
      beg = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return res;
}

int main() {
  scanf("%d %d", &n, &c);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  std::sort(v, v + n);
  printf("%d", sol());
}