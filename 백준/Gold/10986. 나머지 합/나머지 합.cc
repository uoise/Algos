#include <iostream>
int N, M, S = 0, T;
long long R, V[1001];

void solve() {
  for (int i = 0; i < N; i++) {
    scanf("%d", &T);
    T %= M;
    S = (S + T) % M;
    V[S]++;
  }
  R = V[0];
  for (int i = 0; i < M; i++)
    if (V[i] > 1) R += V[i] * (V[i] - 1) / 2;
  printf("%lld\n", R);
}

int main() {
  scanf("%d %d", &N, &M);
  solve();
}