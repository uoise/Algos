#include <iostream>
#define MX 41
int N, M, f[MX];
int fib(int n) {
  if (n == 1 || n == 2) {
    N++;
    return 1;
  } else
    return fib(n - 1) + fib(n - 2);
}

int fibonacci(int m) {
  for (int i = 3; i <= m; i++) {
    M++;
    f[i] = f[i - 1] + f[i - 2];
  }
  return f[m];
}
int main() {
  int t;
  scanf("%d", &t);
   f[1] =1;
   f[2] =1;
  fib(t);
  fibonacci(t);
  printf("%d %d\n", N, M);
}