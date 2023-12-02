#include <cstdio>
#include <queue>

std::priority_queue<long long> q;
long long sol() {
  int n;
  long long x, r = 0;
  scanf("%d", &n);
  while (n--) {
    scanf("%lld", &x);
    q.push(-x);
  }

  while (q.size() > 1) {
    x = -q.top();
    q.pop();
    x -= q.top();
    q.pop();
    r += x;
    q.push(-x);
  }

  q.pop();

  return r;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) printf("%lld\n", sol());
}