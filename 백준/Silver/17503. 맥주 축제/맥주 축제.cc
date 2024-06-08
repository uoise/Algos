#include <cstdio>
#include <queue>

std::priority_queue<std::pair<int, int>> q;
std::priority_queue<int> p;
int n, m, k, r;
int sol() {
  scanf("%d %d %d", &n, &m, &k);
  while (k--) {
    int v, c;
    scanf("%d %d", &v, &c);
    q.push({-c, v});
  }

  while (q.size()) {
    auto [c, v] = q.top();
    q.pop(); 
    p.push(-v);
    r += v;
    if (p.size() > n) {
      r += p.top();
      p.pop();
    }
    if (p.size() == n && r >= m) return -c;
  }
  return -1;
}

int main() { printf("%d", sol()); }