#include <iostream>
#include <string>
using namespace std;
int N, M;
bool W, A, D;
void solve() {
  cin >> N >> M;
  string s;
  int t, siz = 0, beg = 0, c = 0;
  for (int i = 0; i < N; i++) {
    cin >> s;
    t = s.find('#');
    if (!(W || A || D) && !(t < 0)) {
      if (c == 0) {
        if (s[t] != s[t + 1])
          W = true;
        else {
          for (int j = t; j < M; j++)
            if (s[j] == '#') siz++;
          if (siz % 2 == 0)
            W = true;
          else
            beg = t;
        }
      } else if (c < siz) {
        if (s[beg] == '.')
          A = true;
        else if (s[beg + siz - 1] == '.')
          D = true;
      }
      c++;
    }
  }

  if (W)
    cout << "UP\n";
  else if (A)
    cout << "LEFT\n";
  else if (D)
    cout << "RIGHT\n";
  else
    cout << "DOWN\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  solve();
}