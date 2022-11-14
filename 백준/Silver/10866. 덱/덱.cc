#include <iostream>
#include <queue>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int N, c;
  string S;
  cin >> N;
  deque<int> dq;
  while (N--) {
    cin >> S;
    if (S == "size") cout << dq.size() << '\n';
    else if (S == "empty") cout << dq.empty() << '\n';
    else if (S[0] == 'p' && S[3] == 'h') {
      cin >> c;
      if (S[5] == 'f') dq.push_front(c);
      else if (S[5] == 'b') dq.push_back(c);
    } else {
      if (dq.empty()) cout << "-1\n";
      else {
        if (S == "pop_front") {
          cout << dq.front() << '\n';
          dq.pop_front();
        } else if (S == "pop_back") {
          cout << dq.back() << '\n';
          dq.pop_back();
        } else if (S == "front") cout << dq.front() << '\n';
        else if (S == "back") cout << dq.back() << '\n';
      }
    }
  }
}