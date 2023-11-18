#include <algorithm>
#include <cstdio>

std::pair<double, int> v[101];
int pv[101];
void sol(int n) {
  double t, c;
  scanf("%lf", &t);
  v[0] = {t, pv[0]};
  for (int i = 1; i < n; i++) {
    scanf("%lf", &c);
    v[i] = {t + c, pv[i]};
    if (c < 0) t += c;
  }

  std::sort(v, v + n);
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) pv[i] = i + 1;
  sol(n);
  for (int i = 0; i < m; i++) pv[i] = v[m - i - 1].second;
  sol(m);
  for (int i = 0; i < 3; i++) printf("%d\n", v[i].second);
}