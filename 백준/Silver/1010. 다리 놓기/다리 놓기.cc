#include <iostream>

void solve() {
  int N, M, nm, i;
  long long r = 1;
  scanf("%d", &N);
  scanf("%d", &M);
  nm = (M - N) > N ? (M - N) : N;

  for (i = M; i > nm; i--) r *= i;
  for (i = 1; i <= M - nm; i++) r /= i;
  ;
  printf("%lld\n", r);
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
}