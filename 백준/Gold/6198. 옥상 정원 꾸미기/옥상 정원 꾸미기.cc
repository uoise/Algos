#include <cstdio>
#include <stack>

std::stack<int> s;
long long r;
int n, h;
int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &h);
    while (!s.empty() && s.top() <= h) s.pop();
    r += s.size();
    s.push(h);
  }
  printf("%lld", r);
}