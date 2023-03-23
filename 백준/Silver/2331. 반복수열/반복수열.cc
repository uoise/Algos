#include <cmath>
#include <cstdio>
#include <stack>
#include <unordered_set>

std::stack<int> stk;
std::unordered_set<int> s;
int A, P, t, b;
int main() {
  scanf("%d %d", &A, &P);
  while (1) {
    b = s.size();
    s.insert(A);
    if (b == s.size()) break;
    stk.push(A);
    t = 0;
    while (A) {
      t += std::pow(A % 10, P);
      A /= 10;
    }
    A = t;
  }
  while (stk.top() != A) stk.pop();
  printf("%d", stk.size() - 1);
}