#include <cstdio>
#include <cstring>
#include <queue>
#include <string>

bool bv[20001];
std::queue<std::pair<int, std::string>> q;
std::string bfs(const int n) {
  memset(bv, 0, sizeof bv);
  while (!q.empty()) q.pop();
  int c, d;
  std::string s, z;
  bv[1] = 1;
  q.push({1, "1"});
  while (!q.empty()) {
    c = q.front().first, s = q.front().second;
    q.pop();
    for (int i = 0; i < 2; i++) {
      d = (c * 10 + i) % n, z = s + (i ? "1" : "0");
      if (bv[d]) continue;
      if (!d) return z;
      bv[d] = 1;
      q.push({d, z});
    }
  }
  return "BRAK";
}

int main() {
  int T, n;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    printf("%s\n", n == 1 ? "1" : bfs(n).c_str());
  }
}