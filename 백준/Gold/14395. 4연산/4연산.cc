#include <cstdio>
#include <queue>
#include <string>
#include <unordered_set>

using namespace std;
using ll = long long;

constexpr char cc[4] = {'*', '+', '-', '/'};
queue<pair<ll, string>> q;
unordered_set<ll> m;
string sol() {
  ll s, t;
  scanf("%lld %lld", &s, &t);
  if (s == t) return "0";
  m.insert(s);
  q.push({s, ""});
  while (!q.empty()) {
    auto [c, s] = q.front();
    q.pop();
    for (int d = 0; d < 4; d++) {
      ll a;
      if (d == 0) a = c * c;
      if (d == 1) a = c + c;
      if (d == 2) a = c - c;
      if (d == 3) {
        if (!c) continue;
        a = c / c;
      }
      if (a == t) return s + cc[d];
      if (m.count(a)) continue;
      m.insert(a);
      q.push({a, s + cc[d]});
    }
  }
  return "-1";
}

int main() { printf("%s", sol().c_str()); }