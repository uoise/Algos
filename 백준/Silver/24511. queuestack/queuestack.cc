#include <cstdio>
#include <deque>
#include <queue>

std::queue<int> q;
std::deque<int> d;

int n, m, x;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    if (!x) q.push(i);
  }

  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    if (q.empty() || q.front() != i) continue;
    d.push_back(x);
    q.pop();
  }

  scanf("%d", &m);
  while (m--) {
    scanf("%d", &x);
    d.push_front(x);
    printf("%d ", d.back());
    d.pop_back();
  }
}