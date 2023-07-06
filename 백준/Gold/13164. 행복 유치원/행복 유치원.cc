#include <cstdio>
#include <queue>

constexpr int MX = 3e5;
std::priority_queue<int> q;
int n, k, r, v[MX];
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    if (i) q.push(v[i] - v[i - 1]);
  }
    
  --k;
  while (!q.empty()) {
    if (k) --k;
    else r += q.top();
    q.pop();
  }

  printf("%d", r);
}