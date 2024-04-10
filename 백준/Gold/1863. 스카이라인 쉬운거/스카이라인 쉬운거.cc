#include <cstdio>
#include <stack>

std::stack<int> s;
int n, x, y, r;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &x, &y);
    while (s.size() && s.top() > y) {
      r++;
      s.pop();
    }
    if (s.empty() || s.top() != y) s.push(y);
  }

  while (s.size()) {
    if (s.top() > 0) r++;
    s.pop();
  }

  printf("%d", r);
}