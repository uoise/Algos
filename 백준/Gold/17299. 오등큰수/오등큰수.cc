#include <iostream>
#include <stack>
using namespace std;

int cv[1000001];
void sol() {
  int n;
  stack<int> stk;
  cin >> n;
  int nv[n], rv[n];
  for (auto& i : nv) {
    cin >> i;
    ++cv[i];
  }

  for (int i = n - 1; i >= 0; i--) {
    while (!stk.empty() && (cv[nv[i]] >= cv[stk.top()])) stk.pop();
    rv[i] = stk.empty() ? -1 : stk.top();
    stk.push(nv[i]);
  }
  for (const auto& i : rv) cout << i << ' ';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  sol();
}
