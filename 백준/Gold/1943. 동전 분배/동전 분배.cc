#include <cstdio>
#include <queue>
#include <unordered_set>

std::queue<int> q;
std::unordered_set<int> us;
int n, s, v[101][2];
bool clc(int p) {
  if (!p) return 0;
  for (const int& c : us)
    for (int i = v[p][1], a = c + v[p][0]; i && a <= s; i--, a += v[p][0])
      q.push(a);

  while (!q.empty()) {
    us.insert(q.front());
    q.pop();
  }

  return us.count(s) ? 1 : clc(p - 1);
}

bool sol() {
  s = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d", &v[i][0], &v[i][1]);
    s += v[i][0] * v[i][1];
  }
  if (s & 1) return 0;
  s >>= 1;
  us.clear();
  us.insert(0);
  return clc(n);
}

int main() {
  int T = 3;
  while (T--) printf("%d\n", sol());
}