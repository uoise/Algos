#include <cstdio>
#include <queue>

std::priority_queue<int> p;
std::queue<int> q;
int m, k, l;
int main() {
  int n, x;
  scanf("%d %d %d", &n, &m, &k);
  while (n--) {
    scanf("%d", &x);
    p.push(x);
  }

  while (p.size()) {
    int c = p.top();
    p.pop();
    l = l / 2 + c;
    q.push(l);
    if (c - m > k) p.push(c - m);
  }

  printf("%lu\n", q.size());
  while (q.size()) {
    printf("%d\n", q.front());
    q.pop();
  }
}