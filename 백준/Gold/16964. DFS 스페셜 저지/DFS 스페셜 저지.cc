#include <cstdio>
#include <stack>
#include <unordered_set>

std::unordered_set<int> v[100001];
std::stack<int> stk;
int n;
int sol() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) v[0].insert(i);
  for (int i = 1; i < n; i++) {
    int s, e;
    scanf("%d %d", &s, &e);
    v[s].insert(e);
    v[e].insert(s);
  }

  int c = 0, a;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    if (!i && a != 1) return 0;
    while (!v[c].count(a)) {
      if (!stk.top()) return 0;
      c = stk.top();
      stk.pop();
    }
    stk.push(c);
    c = a;
  }
  return 1;
}

int main() { printf("%d", sol()); }