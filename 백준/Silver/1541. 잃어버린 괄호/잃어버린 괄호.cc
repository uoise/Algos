#include <iostream>
using namespace std;
string S;
int R, C, T;
bool beg;
void solve() {
  for (size_t i = 0; i < S.size(); i++) {
    if (S[i] == '+' || S[i] == '-') {
      T = stoi(S.substr(C, i));
      C = i + 1;
      if (!beg) {
        if (S[i] == '-') beg = true;
        R += T;
      } else R -= T;
    }
  }
  T = stoi(S.substr(C, S.size()));
  if (beg) R -= T;
  else R += T;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> S;
  solve();
  cout << R << '\n';
}