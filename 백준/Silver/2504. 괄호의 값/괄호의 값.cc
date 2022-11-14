#include <iostream>
#include <stack>
using namespace std;

int sol(const string s) {
  stack<pair<int, int>> stk;
  int res = 0, tmp;
  for (const auto& c : s) {
    if (c == '(' || c == '[') {
      const int x = (c == '(' ? 2 : 3);
      stk.push({x, 0});
    } else {
      if (stk.empty()) return 0;
      if ((stk.top().first == 2 && c == ']') ||
          (stk.top().first == 3 && c == ')'))
        return 0;

      if (stk.top().second)
        stk.top().second *= stk.top().first;
      else
        stk.top().second = stk.top().first;
      tmp = stk.top().second;
      stk.pop();
      if (stk.empty())
        res += tmp;
      else
        stk.top().second += tmp;
    }
  }

  return res;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string s;
  cin >> s;
  cout << sol(s);
}