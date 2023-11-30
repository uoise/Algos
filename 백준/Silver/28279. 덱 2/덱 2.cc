#include <cstdio>
#include <deque>
std::deque<int> q;
int main() {
  int n, x, o, r;
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &x);
    if (x < 3) {
      scanf("%d", &o);
      if (x == 1)
        q.push_front(o);
      else
        q.push_back(o);
      continue;
    }
    if (x == 3) {
      r = q.empty() ? -1 : q.front();
      if (!q.empty()) q.pop_front();
    } else if (x == 4) {
      r = q.empty() ? -1 : q.back();
      if (!q.empty()) q.pop_back();
    } else if (x == 5) {
      r = q.size();
    } else if (x == 6) {
      r = q.empty() ? 1 : 0;
    } else if (x == 7) {
      r = q.empty() ? -1 : q.front();
    } else if (x == 8) {
      r = q.empty() ? -1 : q.back();
    }
    printf("%d\n", r);
  }
}