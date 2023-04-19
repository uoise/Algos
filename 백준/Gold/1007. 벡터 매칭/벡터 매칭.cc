#include <cmath>
#include <cstdio>

using ll = long long;

int n;
ll yy, xx, vv[20][2];
ll llm(const ll& x, const ll& y) { return x > y ? y : x; }
ll clc(int len, int idx, ll cy, ll cx) {
  if (len == n / 2) return pow(yy - cy * 2, 2) + pow(xx - cx * 2, 2);

  ll r = 1e13;
  for (int i = idx; i < n; i++)
    r = llm(r, clc(len + 1, i + 1, cy + vv[i][0], cx + vv[i][1]));
    
  return r;
}

void sol() {
  scanf("%d", &n);
  yy = 0, xx = 0;
  for (int i = 0; i < n; i++) {
    scanf("%lld %lld", &vv[i][0], &vv[i][1]);
    yy += vv[i][0], xx += vv[i][1];
  }
  ll r = clc(0, 0, 0, 0);

  printf("%.6lf\n", sqrt(r));
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) sol();
}