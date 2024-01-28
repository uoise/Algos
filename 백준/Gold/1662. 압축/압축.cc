#include <cstdio>
#include <stack>
std::stack<int> n, l;
char s[51];
int c;
int main() {
  scanf("%s", s);
  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] == '(') {
      l.push(--c), n.push(s[i - 1] - '0');
      c = 0;
    } else if (s[i] == ')') {
      c = c * n.top() + l.top();
      l.pop(), n.pop();
    } else {
      ++c;
    }
  }
  printf("%d", c);
}