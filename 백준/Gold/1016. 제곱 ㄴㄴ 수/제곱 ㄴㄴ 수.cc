#include <cstdio>

using ll = long long;
ll mn, mx, res;
bool rv[1000001];
int main() {
  scanf("%lld %lld", &mn, &mx);
  for (ll i = 2; i * i <= mx; i++) {
    ll mul = 1LL * i * i;
    ll beg = mn / mul;
    for (ll j = mul * beg; j <= mx; j += mul) {
      if (j < mn) continue;
      rv[j - mn] = 1;
    }
  }

  for (ll i = 0; i <= mx - mn; i++) if (!rv[i]) ++res;
  printf("%d", res);
}