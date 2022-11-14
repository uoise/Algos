#include <iostream>
using namespace std;
int N, C;
string S;
void solve() {
  C = 0;
  for (int i = 0; i < S.size(); i++) {
    C += (S[i] == '(') ? 1 : -1;
    if (C < 0) {
      cout << "NO" << '\n';
      return;
    }
  }
  if (C == 0) cout << "YES" << '\n';
  else cout << "NO" << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> N;
  while (N--) {
    cin >> S;
    solve();
  }
}