#include <iostream>
unsigned short dp[1001];
void sol(const int a, const int pos = 1) {
  int i = 2, t = a;
  while (i <= a) {
    if (t % i == 0) {
      dp[i] += pos;
      t /= i;
    } else
      i++;
  }
}

void solve() {
  int N, K, i, t;
  scanf("%d", &N);
  scanf("%d", &K);
  for (i = N - K + 1; i <= N; i++) sol(i);
  for (i = 2; i <= K; i++) sol(i, -1);
  t = 1;
  for (i = 1; i <= N; i++)
    while (dp[i]--) {
      t *= i;
      t = t >= 10007 ? t % 10007 : t;
    }
  printf("%d", t);
}

int main() { solve(); }