#include <iostream>

void solve() {
  int N, K, nk, kn, i;
  long long r = 1, t = 1;
  scanf("%d", &N);
  scanf("%d", &K);
  if (N - K > K) {
    nk = N - K;
    kn = K;
  } else {
    nk = K;
    kn = N - K;
  }
  for (i = N; i > nk; i--) r *= i;
  for (i = kn; i > 1; i--) t *= i;
  printf("%d", r / t);
}

int main() { solve(); }