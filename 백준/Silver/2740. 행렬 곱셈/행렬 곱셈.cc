#include <iostream>
int R[100][100];
int main() {
  int n, m, o;
  scanf("%d %d", &n, &m);
  int A[n][m];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) scanf("%d", &A[i][j]);

  scanf("%d %d", &m, &o);
  int B[m][o];
  for (int i = 0; i < m; i++)
    for (int j = 0; j < o; j++) scanf("%d", &B[i][j]);

  for (int i = 0; i < n; i++) 
    for (int j = 0; j < m; j++)
      for (int k = 0; k < o; k++) R[i][k] += A[i][j] * B[j][k];
  

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < o; j++) printf("%d ", R[i][j]);
    printf("\n");
  }
}