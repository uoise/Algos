#include <cstdio>
#include <queue>

constexpr int MX = 5e5 + 1;
std::deque<char> q;
int n, k, p, l;
char s[MX];
int main() {
  scanf("%d %d %s", &n, &k, s);
  for (int i = 0; i < n; i++) {
    while (k && !q.empty() && q.back() < s[i]) {
      q.pop_back();
      k--;
    }
    q.push_back(s[i]);
  }
  for (int i = 0; i < q.size() - k; i++) printf("%c", q[i]);
}