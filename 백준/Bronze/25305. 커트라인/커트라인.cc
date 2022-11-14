#include <iostream>
#include <queue>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, k, t;
  cin >> n >> k;
  priority_queue<int> pq;
  while (n--) {
    cin >> t;
    pq.push(t);
  }
  k--;
  while (k--) {
    pq.pop();
  }
  cout << pq.top();
}