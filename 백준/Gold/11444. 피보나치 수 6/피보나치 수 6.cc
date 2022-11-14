#include <iostream>
#define ll long long
ll n, c = 1000000007;
void pow(ll rr[][2], ll aa[][2]) {
  ll tmp[2][2];
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) tmp[i][j] = 0;

  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++)
        tmp[i][k] = (tmp[i][k] + rr[i][j] * aa[j][k]) % c;

  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) rr[i][j] = tmp[i][j];
}

int main() {
  scanf("%lld", &n);
  ll A[2][2] = {{1, 1}, {1, 0}}, R[2][2] = {{1, 0}, {0, 1}};
  n--;
  while (n > 0) {
    if (n % 2 == 1) pow(R, A);
    pow(A, A);
    n /= 2;
  }
  printf("%d\n", R[0][0]);
}