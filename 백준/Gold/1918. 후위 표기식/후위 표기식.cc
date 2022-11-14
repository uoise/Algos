#include <iostream>
#include <stack>

using namespace std;

string s;
string sol() {
  string r = "";
  stack<char> sk;
  for (const auto& c : s) {
    if (c == ')') {
      while (!sk.empty() && sk.top() != '(') {
        r += sk.top();
        sk.pop();
      }
      sk.pop();
    } else if (c == '(')
      sk.push(c);
    else if (c == '*' || c == '/') {
      while (!sk.empty() && (sk.top() == '*' || sk.top() == '/')) {
        r += sk.top();
        sk.pop();
      }
      sk.push(c);
    } else if (c == '+' || c == '-') {
      while (!sk.empty() && sk.top() != '(') {
        r += sk.top();
        sk.pop();
      }
      sk.push(c);
    } else
      r += c;
  }

  while (!sk.empty()) {
    r += sk.top();
    sk.pop();
  }

  return r;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> s;
  cout << sol();
}