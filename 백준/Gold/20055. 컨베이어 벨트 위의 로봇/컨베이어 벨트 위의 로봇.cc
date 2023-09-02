#include <cstdio>
#include <deque>

std::deque<int> q;
bool v[101];
int n, k, c, r, x;
int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n * 2; i++) {
    scanf("%d", &x);
    q.push_back(x);
  }

  while (c < k && ++r) {
    q.push_front(q.back());
    q.pop_back();
    for (int i = n - 2; i >= 0; i--) v[i + 1] = v[i];
    v[0] = v[n - 1] = 0;
    for (int i = n - 2; i; i--) {
      if (!v[i] || v[i + 1] || !q[i + 1]) continue;
      if (!--q[i + 1]) ++c;
      v[i + 1] = i == n - 2 ? 0 : v[i];
      v[i] = 0;
    }
    if (!q[0]) continue;
    v[0] = 1;
    if (!--q[0]) ++c;
  }
  
  printf("%d", r);
}