#include <iostream>
#include <queue>
using namespace std;
deque<int> v, dq;
int N, M, R;

void solve() {
  R = 0;
  while (!v.empty()) {
    if (dq.front() == v.front()) {
      dq.pop_front();
      v.pop_front();
    } else {
      int i;
      for (i = 0; i < dq.size(); i++) {
        if (dq.front() == v.front()) break;
        dq.push_back(dq.front());
        dq.pop_front();
      }
      R += (dq.size() - i < i) ? dq.size() - i : i;
      dq.pop_front();
      v.pop_front();
    }
  }
}
int main() {
  scanf("%d %d", &N, &M);

  for (size_t i = 1; i <= N; i++) dq.push_back(i);
  for (size_t i = 0; i < M; i++) {
    scanf("%d", &R);
    v.push_back(R);
  }
  solve();
  printf("%d\n", R);
}