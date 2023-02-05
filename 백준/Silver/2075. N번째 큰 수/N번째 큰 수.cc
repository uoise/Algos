#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> q;
int n, x, r, i, j;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout.tie(0);
  cin >> n;
  for (; i < n; i++)
    for (j = 0; j < n; j++) {
      cin >> r;
      q.push(-r);
      if (q.size() > n) q.pop();
    }
  cout << -q.top();
}