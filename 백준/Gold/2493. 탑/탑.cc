#include <iostream>
#include <stack>

using namespace std;

int n;
void sol() {
  stack<pair<int, int>> sk;
  int rv[n], x;
  for (int i = 0; i < n; i++) {
    cin >> x;
    while (!sk.empty() && sk.top().first < x) sk.pop();
    rv[i] = sk.empty() ? 0 : sk.top().second;
    sk.push({x, i + 1});
  }

  for (int i = 0; i < n; i++) cout << rv[i] << ' ';
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  sol();
}