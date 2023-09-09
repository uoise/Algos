#include <cstdio>
#include <queue>

std::priority_queue<int> pq;
std::priority_queue<int, std::vector<int>, std::greater<>> rq;
int t, m, x, c;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &m);
    printf("%d\n", m / 2 + m % 2);
    c = 0;
    while (!pq.empty()) pq.pop();
    while (!rq.empty()) rq.pop();
    for (int i = 0; i < m; i++) {
      scanf("%d", &x);
      if (i & 1) {
        rq.push(x);
      } else {
        pq.push(x);
        if (!pq.empty() && !rq.empty() && (pq.top() > rq.top())) {
          rq.push(pq.top());
          pq.push(rq.top());
          rq.pop();
          pq.pop();
        }
        printf("%d ", pq.top());
        if (++c == 10) {
          c = 0;
          printf("\n");
        }
      }
    }
    printf("\n");
  }
}