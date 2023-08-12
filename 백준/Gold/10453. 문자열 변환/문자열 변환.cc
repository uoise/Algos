#include <algorithm>
#include <cstdio>
#include <queue>

constexpr int MX = 1e5;

std::queue<int> a, b;
char s[MX];
int T, n, r;
int sol() {
  n = 0, r = 0;
  scanf("%s", s);
  while (s[n++] != '\0') if (n && s[n] == 'a') a.push(n);

  scanf("%s", s);
  for (int i = 1; i < n - 1; i++) if (s[i] == 'a') b.push(i);

  while (!a.empty()) {
    r += std::abs(a.front() - b.front());
    a.pop();
    b.pop();
  }

  return r;
}

int main() {
  scanf("%d", &T);
  while (T--) printf("%d\n", sol());
}