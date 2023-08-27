#include <cstdio>
#include <stack>

std::stack<int> s;
bool sol() {
  int n, x, c = 1;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &x);
    if (x == c) {
      ++c;
      continue;
    }

    while (!s.empty() && c == s.top()) {
      s.pop();
      ++c;
    }

    s.push(x);
  }

  while (!s.empty() && c == s.top()) {
    s.pop();
    ++c;
  }
  
  return s.empty();
}

int main() { printf("%s", sol() ? "Nice" : "Sad"); }