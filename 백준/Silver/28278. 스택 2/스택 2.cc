#include <cstdio>
#include <stack>
std::stack<int> s;
int main() {
  int n, x, o, r;
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &x);
    if (x == 1) {
      scanf("%d", &o);
      s.push(o);
      continue;
    }

    if (x == 2) {
      r = s.empty() ? -1 : s.top();
      if (!s.empty()) s.pop();
    } else if (x == 3) {
      r = s.size();
    } else if (x == 4) {
      r = s.empty() ? 1 : 0;
    } else if (x == 5) {
      r = s.empty() ? -1 : s.top();
    }
    printf("%d\n", r);
  }
}