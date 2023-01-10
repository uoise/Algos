#include <cstdio>
#include <queue>
#include <unordered_set>

using namespace std;

unordered_set<int> v;
queue<pair<int, int>> q;
constexpr long long INF = 1e9 + 1;
long long x, n;
int a, b;
int sol() {
  q.push({a, 1});
  v.insert(a);
  while (!q.empty()) {
    x = q.front().first, a = q.front().second + 1;
    q.pop();
    n = x * 2;
    if (n > INF) continue;
    if (n == b)
      return a;
    else if (v.find(n) == v.end()) {
      q.push({n, a});
      v.insert(n);
    }
    n = x * 10 + 1;
    if (n > INF) continue;
    if (n == b)
      return a;
    else if (v.find(n) == v.end()) {
      q.push({n, a});
      v.insert(n);
    }
  }
  return -1;
}

int main() {
  scanf("%d %d", &a, &b);
  printf("%d", sol());
}