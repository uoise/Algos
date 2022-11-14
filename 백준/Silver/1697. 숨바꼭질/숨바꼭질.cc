#include <iostream>
#include <queue>
#define MX 100001
using namespace std;
int n, k, v[MX];
queue<int> q;
void bfs() {
  v[n] = 1;
  q.push(n);
  while (!q.empty()) {
    int u = q.front();
    if (u == k) break;
    q.pop();
    if (u + 1 < MX && v[u + 1] == 0) {
      v[u + 1] = v[u] + 1;
      q.push(u + 1);
    }
    if (u * 2 < MX && v[u * 2] == 0) {
      v[u * 2] = v[u] + 1;
      q.push(u * 2);
    }
    if (u - 1 >= 0 && v[u - 1] == 0) {
      v[u - 1] = v[u] + 1;
      q.push(u - 1);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> k;
  bfs();
  cout << --v[k];
}