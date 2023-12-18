#include <cstdio>
#include <stack>

std::stack<int> s[4];
bool sol() {
  int n, x, c;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    c = 0;
    for (int j = 0; j < 4; j++) {
      if (s[j].empty() || s[j].top() < x) {
        s[j].push(x);
        c = 1;
        break;
      }
    }
    if (!c) return 0;
  }
  return 1;
}

int main() { printf("%s", sol() ? "YES" : "NO"); }