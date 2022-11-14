#include <iostream>
long sol(long a, const int b) {
  long r = 0;
  while (a >= b) {
    r += (a / b);
    a /= b;
  }
  return r;
}
void solve() {
  long N, M, rt, rf, rr;
  scanf("%ld", &N);
  scanf("%ld", &M);
  rt = sol(N, 2) - sol(M, 2) - sol(N - M, 2);
  rf = sol(N, 5) - sol(M, 5) - sol(N - M, 5);
  rr = (rf < rt) ? rf : rt;
  printf("%ld\n", rr);
}
int main() { solve(); }