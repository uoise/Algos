#include <cstdio>
#include <queue>

std::queue<int> q;
int n, m, k, s, r, v[100001];
int sol() {
  s = 0, r = 0;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; i++) scanf("%d", &v[i]);
  for (int i = 0; i < n + m - 1; i++) {
    s += v[i % n];
    q.push(i % n);
    while (q.size() > m || s >= k) {
      s -= v[q.front()];
      q.pop();
    }
    r += q.size() == m;
  }
  while (q.size()) q.pop();
  return n == m ? r / n : r;
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) printf("%d\n", sol());
}