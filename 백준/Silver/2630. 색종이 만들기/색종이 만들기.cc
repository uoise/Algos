#include <iostream>
bool M[129][129];
int B, W;
void solve(const int siz, const int xb, const int yb, const int xe,
           const int ye) {
  bool t = M[xb][yb], res = true;
  for (int i = xb; i <= xe && res; i++)
    for (int j = yb; j <= ye && res; j++)
      if (M[i][j] != t) res = false;
  if (res) {
    (t) ? B++ : W++;
    return;
  }
  if (siz > 1) {
    int s = siz / 2;
    solve(s, xb, yb, xb + s - 1, yb + s - 1);  // (1,1) (2,2)
    solve(s, xb + s, yb, xe, yb + s - 1);      // (3,1) (4,2)
    solve(s, xb, yb + s, xb + s - 1, ye);      // (1,3) (2,4)
    solve(s, xb + s, yb + s, xe, ye);          // (3,3) (4,4)}
  }
}
int main() {
  int N, t;
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++) {
      scanf("%d", &t);
      if (t == 1) M[i][j] = true;
    }

  solve(N, 1, 1, N, N);
  printf("%d\n%d\n", W, B);
}