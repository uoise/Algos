#include <cstdio>
#include <queue>

std::priority_queue<int> q;
int n, x, t, r;
int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &x);
    q.push(-x);
  }
  while (q.size() > 1) {
    t = -q.top();
    q.pop();
    t -= q.top();
    q.pop();
    q.push(-t);
    r += t;
  }
  printf("%d", r);
}