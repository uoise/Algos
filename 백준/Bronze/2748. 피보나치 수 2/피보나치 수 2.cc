#include <cstdio>
using ll = long long;
ll dp[91];
ll fib(int n) {
  if (n <= 1) return n;
  if (dp[n]) return dp[n];
  return dp[n] = fib(n - 1) + fib(n - 2);
}

int main() {
  int n;
  scanf("%d", &n);
  printf("%lld", fib(n));
}