#include <iostream>
#include <queue>
using namespace std;

void solve() {
  int N, M, c;
  scanf("%d %d", &N, &M);
  M++;
  deque<pair<int, int>> DQ;
  std::priority_queue<int> PQ;
  for (size_t i = 1; i <= N; i++) {
    scanf("%d", &c);
    PQ.push(c);
    DQ.push_back(make_pair(i, c));
  }
  c = 1;
  while (true) {
    if (DQ.front().second == PQ.top()) {
      if (DQ.front().first == M)
        break;
      else{
        PQ.pop();
        c++;
      }
    }
    if (DQ.front().second < PQ.top()) DQ.push_back(DQ.front());
    DQ.pop_front();
  }
  printf("%d\n", c);
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) solve();
}