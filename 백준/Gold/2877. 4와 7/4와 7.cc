#include <cstdio>
#include <stack>

std::stack<int> t;
int k;
int main() {
  scanf("%d", &k);
  ++k;
  while (k) {
    t.push(k % 2);
    k >>= 1;
  }

  t.pop();
  while (t.size()) {
    printf("%d", t.top() ? 7 : 4);
    t.pop();
  }
}