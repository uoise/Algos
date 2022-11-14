#include <iostream>
using namespace std;
bool M[65][65];
string R = "";
void solve(const int siz, const int xb, const int yb, const int xe,
           const int ye) {
  bool t = M[xb][yb], res = true;
  for (int i = xb; i <= xe && res; i++)
    for (int j = yb; j <= ye && res; j++)
      if (M[i][j] != t) res = false;
  if (res) {
    if (t)
      R += "1";
    else
      R += "0";
    return;
  }
  if (siz > 1) {
    int s = siz / 2;
    R += "(";
    solve(s, xb, yb, xb + s - 1, yb + s - 1);  // (1,1) (2,2)
    solve(s, xb, yb + s, xb + s - 1, ye);      // (1,3) (2,4)
    solve(s, xb + s, yb, xe, yb + s - 1);      // (3,1) (4,2)
    solve(s, xb + s, yb + s, xe, ye);          // (3,3) (4,4)
    R += ")";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N;
  string s;
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> s;
    for (int j = 0; j < N; j++)
      if (s[j] == '1') M[i][j + 1] = true;
      else if (s[j] == '0') M[i][j + 1] = false;      
  }

  solve(N, 1, 1, N, N);
  cout << R << '\n';
}