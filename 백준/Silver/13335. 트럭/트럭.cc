#include <cstdio>
#include <queue>

std::deque<int> q;
int n, w, l, s, x, r;
int main() {
  scanf("%d %d %d", &n, &w, &l);
  for (int i = 0; i < w; i++) q.push_front(0);
  while (n--) {
    scanf("%d", &x);
    s -= q.back();
    q.pop_back();
    while (s + x > l) {
      q.push_front(0);
      s -= q.back(), ++r;
      q.pop_back();
    }
    s += x, ++r;
    q.push_front(x);
  }

  while (s) {
    s -= q.back(), ++r;
    q.pop_back();
  }
  printf("%d", r);
}