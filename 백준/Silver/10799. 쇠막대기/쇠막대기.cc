#include <iostream>
#include <stack>
using namespace std;
string s;
int r, l;
stack<bool> t;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '(') {
      t.push(1);
    } else {
      t.pop();
      r += (s[i - 1] == '(' ? t.size() : 1);
    }
  }
  cout << r;
}