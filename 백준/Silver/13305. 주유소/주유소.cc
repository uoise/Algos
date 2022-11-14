#include <iostream>
int N, C[100001], L[100000], T;
long long res;
void solve() {
  T = C[0];
  for (size_t i = 1; i < N; i++) {
    res += (T * L[i]);
    T = (T < C[i]) ? T : C[i];
  }
}
int main() {
  scanf("%d", &N);
  for (size_t i = 1; i < N; i++) scanf("%d", &L[i]);
  for (size_t i = 0; i < N; i++) scanf("%d", &C[i]);
  solve();
  printf("%lld\n", res);
}