#include <iostream>
#define ll long long
int A[5][5], R[5][5], n;
void pow(int rr[][5], int aa[][5]) {
  ll tmp[n][n];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) tmp[i][j] = 0;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++)
        tmp[i][k] = (tmp[i][k] + rr[i][j] * aa[j][k]) % 1000;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) rr[i][j] = tmp[i][j];
}

int main() {
  ll b;
  scanf("%d %lld", &n, &b);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      scanf("%d", &A[i][j]);
      R[i][j] = (i == j);
    }
  while (b > 0) {
    if (b % 2 == 1) pow(R, A);
    pow(A, A);
    b /= 2;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) printf("%d ", R[i][j]);
    printf("\n");
  }
}
