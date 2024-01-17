#include <cstdio>
#include <cstring>
#include <queue>

constexpr int MX = 10001;
std::queue<int> v[26];
char s[MX];
void sol() {
  int rm = MX, rd = -1, k, l;
  scanf("%s %d", s, &k);
  for (int i = 0; i < strlen(s); i++) {
    v[s[i] - 'a'].push(i);
    if (v[s[i] - 'a'].size() != k) continue;
    l = i - v[s[i] - 'a'].front() + 1;
    rm = std::min(l, rm), rd = std::max(l, rd);
    v[s[i] - 'a'].pop();
  }

  if (rd < 0) printf("-1\n");
  else printf("%d %d\n", rm, rd);
  for (auto& q : v) while (!q.empty()) q.pop();
}

int main() {
  int T;
  scanf("%d", &T);
  while (T--) sol();
}