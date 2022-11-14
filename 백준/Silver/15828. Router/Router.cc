#include <iostream>
#include <queue>

using namespace std;

int n, p;
void sol() {
  queue<int> q;
  while (p >= 0) {
    cin >> p;
    if (p > 0 && q.size() < n)
      q.push(p);
    else if (!p)
      q.pop();
  }
  if (q.empty())
    cout << "empty";
  else
    while (!q.empty()) {
      cout << q.front() << ' ';
      q.pop();
    }
}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  sol();
}