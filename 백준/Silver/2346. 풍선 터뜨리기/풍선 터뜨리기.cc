#include <cstdio>
#include <deque>

std::deque<std::pair<int, int>> q;
int main() {
  int n, x, r;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    q.push_back({i, x});
  }

  while (!q.empty()) {
    printf("%d ", q.front().first);
    x = q.front().second;
    q.pop_front();

    if (x > 0) {
      while (x-- > 0) {
        q.push_back(q.front());
        q.pop_front();
      }
    }

    if (x < 0) {
      while (x++ < 0) {
        q.push_front(q.back());
        q.pop_back();
      }
    }
  }
}