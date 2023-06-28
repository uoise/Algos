#include <cstring>
#include <iostream>
#include <queue>

constexpr int MX = 1e5 + 1;
std::queue<int> q;
int N, K, v[MX];
void bfs() {
  v[N] = 1;
  q.push(N);
  while (!q.empty()) {
    const int cur = q.front();
    q.pop();
    int nxt = cur;
    if (nxt != 0) {
      while (nxt < MX) {
        if (v[nxt] > v[cur]) {
          v[nxt] = v[cur];
          q.push(nxt);
        }
        nxt *= 2;
      }
    }
    if (cur + 1 < MX && v[cur + 1] > v[cur] + 1) {
      v[cur + 1] = v[cur] + 1;
      q.push(cur + 1);
    }
    if (cur - 1 >= 0 && v[cur - 1] > v[cur] + 1) {
      v[cur - 1] = v[cur] + 1;
      q.push(cur - 1);
    }
  }
}

int main() {
  scanf("%d %d", &N, &K);
  memset(v, 0x3f, sizeof v);
  bfs();
  printf("%d", --v[K]);
}