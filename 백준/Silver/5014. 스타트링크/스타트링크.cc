#include <cstdio>
#include <queue>
int f, s, g, u, d, n, v[1000001];
std::queue<int> q;
void sol() {
  v[s] = 1;
  q.push(s);
  while (!q.empty()) {
    s = q.front();
    if (s == g) {
      printf("%d", v[s] - 1);
      return;
    }
    q.pop();
    n = s + u;
    if (n <= f && !v[n]) {
      v[n] = v[s] + 1;
      q.push(n);
    }
    n = s - d;
    if (n > 0 && !v[n]) {
      v[n] = v[s] + 1;
      q.push(n);
    }
  }
  printf("use the stairs");
}
int main() {
  scanf("%d %d %d %d %d", &f, &s, &g, &u, &d);
  sol();
}