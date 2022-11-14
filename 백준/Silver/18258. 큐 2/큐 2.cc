#include <iostream>
#include <queue>
using namespace std;
queue<int> Q;
int N, T;
string S;
void solve() {
  for (size_t i = 0; i < N; i++) {
    cin >> S;
    if (S == "push") {
      cin >> T;
      Q.push(T);
    } else if (S == "pop") {
      if (Q.empty())
        cout << "-1\n";
      else {
        cout << Q.front() << '\n';
        Q.pop();
      }
    } else if (S == "size")
      cout << Q.size() << '\n';
    else if (S == "empty")
      cout << Q.empty() << '\n';
    else if (S == "front") {
      if (Q.empty())
        cout << "-1\n";
      else
        cout << Q.front() << '\n';
    } else if (S == "back") {
      if (Q.empty())
        cout << "-1\n";
      else
        cout << Q.back() << '\n';
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> N;
  solve();
}