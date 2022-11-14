#include <iostream>
using namespace std;
int N;
string S;
void solve() {
  char STK[S.size()], cnt = 0;
  for (int i = 0; i < S.size(); i++) {
    if (S[i] == '[' || S[i] == ']' || S[i] == '(' || S[i] == ')') {
      STK[cnt] = S[i];
      if (STK[cnt] == ']') {
        if (STK[cnt - 1] == '[' && cnt != 0)
          cnt--;
        else {
          cout << "no" << '\n';
          return;
        }
      } else if (STK[cnt] == ')') {
        if (STK[cnt - 1] == '(' && cnt != 0)
          cnt--;
        else {
          cout << "no" << '\n';
          return;
        }
      } else
        cnt++;
    }
  }
  if (cnt > 0)
    cout << "no" << '\n';
  else
    cout << "yes" << '\n';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  while (true) {
    getline(cin, S);
    if (S == ".") break;
    solve();
  }
}