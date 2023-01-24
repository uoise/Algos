#include <cstdio>
#include <queue>

using namespace std;

priority_queue<int> pq, rq;
int n, r, x, c;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    if (x > 1) pq.push(x);
    else if (x < 1) rq.push(-x);
    else ++r;
  }
    
  while (pq.size() > 1) {
    c = pq.top();
    pq.pop();
    c *= pq.top();
    pq.pop();
    r += c;
  }
  if (!pq.empty()) r += pq.top();

  while (rq.size() > 1) {
    c = -rq.top();
    rq.pop();
    c *= -rq.top();
    rq.pop();
    r += c;
  }
  if (!rq.empty()) r -= rq.top();

  printf("%d", r);
}