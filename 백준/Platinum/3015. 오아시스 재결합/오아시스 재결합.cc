#include <iostream>
#include <stack>

using namespace std;
using ll = long long;

ll sol(int n) {
  ll res = 0;
  int nv[n];
  for (auto& i : nv) cin >> i;
  stack<pair<ll, ll>> stk;
  for (const auto& i : nv) {
    int cnt = 1;
    while (!stk.empty() && (stk.top().first <= i)) {
      res += stk.top().second;
      if (stk.top().first == i) {
        cnt = ++stk.top().second;
      }
      stk.pop();
    }
    if (!stk.empty()) ++res;
    stk.push({i, cnt});
  }
  return res;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n;
  cin >> n;
  cout << sol(n);
}