#include <algorithm>
#include <cstdio>

constexpr int CAL[] = {0, 31, 61, 92, 122, 153, 184, 214, 245},
              INF = 31 * 5 + 30 * 4, MX = 1e5 + 1;

std::pair<int, int> dv[MX];
int clc(const int& m, const int& d) {
  if (m < 3) return 1;
  if (m > 11) return INF + 1;
  return CAL[m - 3] + d;
}

int main() {
  int n, s, e, m, d, c = 0, r = 0;
  scanf("%d", &n);
  while (n--) {
    scanf("%d %d", &m, &d);
    s = clc(m, d);
    scanf("%d %d", &m, &d);
    e = clc(m, d);
    if (s > MX || !e) continue;
    dv[c++] = {s, e};
  }

  n = c;
  c = 1, d = 0;
  std::sort(dv, dv + n);
  for (int i = 0; i < n; i++) {
    if (dv[i].first <= c) {
      d = std::max(d, dv[i].second);
    } else if (dv[i].first <= d) {
      ++r, c = d, --i;
    } else {
      d = 0;
      break;
    }
  }
  if (d > c) c = d, ++r;

  printf("%d", c <= INF ? 0 : r);
}