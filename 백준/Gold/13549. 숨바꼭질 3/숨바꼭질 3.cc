#include <iostream>
#include <queue>
#define MX 100001
using namespace std;
int N, K, v[MX];
queue<int> q;

void bfs() {
  v[N] = 1;
  q.push(N);
  while (!q.empty()) {
    const int cur = q.front();
    q.pop();
    int nxt = cur;
    if (nxt != 0) {
      while (nxt < MX) {
        if (v[nxt] == 0) {
          v[nxt] = v[cur];
          q.push(nxt);
        }
        nxt *= 2;
      }
    }
    if (cur + 1 < MX && v[cur + 1] == 0) {
      v[cur + 1] = v[cur] + 1;
      q.push(cur + 1);
    }
    if (cur - 1 >= 0 && v[cur - 1] == 0) {
      v[cur - 1] = v[cur] + 1;
      q.push(cur - 1);
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> N >> K;
  bfs();
  cout << --v[K];
}