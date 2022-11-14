#include <iostream>
#include <queue>
using namespace std;

void solve() {
  int N, t;
  cin >> N;
  priority_queue<int, vector<int>, greater<int>> pq;
  while (N--) {
    cin >> t;
    pq.push(t);
  }
  while (!pq.empty()) {
    cout << pq.top() << '\n';
    pq.pop();
  }
}
int main() { solve(); }