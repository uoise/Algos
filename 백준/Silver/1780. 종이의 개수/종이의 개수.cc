#include <iostream>
using namespace std;
int M[2187][2187], R[3];

void sol(const int siz, const int x = 0, const int y = 0) {
  int t = M[x][y];
  bool res = true;
  for (int i = x; i < x + siz && res; i++)
    for (int j = y; j < y + siz && res; j++)
      if (M[i][j] != t) res = false;
  if (res) {
    R[t + 1]++;
    return;
  }
  if (siz > 2) {
    int s = siz / 3;
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) sol(s, x + (i * s), y + (j * s));
  }  // 012/345/678
}
int main() {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; i++)
    for (int j = 0; j < N; j++) scanf("%d", &M[i][j]);
  sol(N);
  printf("%d\n%d\n%d\n", R[0], R[1], R[2]);
}