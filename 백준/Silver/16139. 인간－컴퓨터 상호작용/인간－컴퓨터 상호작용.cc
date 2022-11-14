#include <iostream>
using namespace std;
int tp[200001][26];

void solve() {
  string S;
  cin >> S;
  int M;
  cin >> M;
  for (int i = 1; i <= S.size(); i++) {
    if (i != 0)
      for (int j = 0; j < 26; j++) tp[i][j] = tp[i - 1][j];
    tp[i][S[i - 1] - 'a']++;
  }

  for (int i = 0; i < M; i++) {
    char c;
    int l, r;
    cin >> c >> l >> r;
    cout << (tp[r + 1][c - 'a'] - tp[l][c - 'a']) << '\n';
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
}
