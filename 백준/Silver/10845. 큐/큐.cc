#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<string> o = {"push", "size", "empty", "pop", "front"};
deque<int> q;
string s;
int n, x, y;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout.tie(0);
  cin >> n;
  while (n--) {
    cin >> s;
    if (o[0] == s) {
      cin >> x;
      q.push_back(x);
    } else {
      if (o[1] == s)
        cout << q.size();
      else if (o[2] == s)
        cout << q.empty();
      else {
        if (q.empty())
          cout << -1;
        else if (o[3] == s) {
          cout << q.front();
          q.pop_front();
        } else if (o[4] == s) {
          cout << q.front();
        } else
          cout << q.back();
      }
      cout << '\n';
    }
  }
}