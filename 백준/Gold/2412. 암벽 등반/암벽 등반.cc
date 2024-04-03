#include <cstdio>
#include <queue>
#include <unordered_map>

using ll = long long;

constexpr ll MX = 1e6 + 1LL;
std::unordered_map<ll, int> s;
std::queue<ll> q;
int T;
int sol() {
  s.insert({0, 1});
  q.push(0);
  while (q.size()) {
    auto c = q.front();
    q.pop();
    int x = c / MX, y = c % MX;
    for (int xx = -2; xx < 3; xx++) {
      for (int yy = -2; yy < 3; yy++) {
        int ax = x + xx, ay = y + yy;
        ll a = MX * ax + ay;
        if (s[a] >= 0) continue;
        s[a] = s[c] + 1;
        if (ay == T) return s[a] - 1;
        q.push(a);
      }
    }
  }
  return -1;
}

int main() {
  int n, x, y;
  scanf("%d %d", &n, &T);
  while (n--) {
    scanf("%d %d", &x, &y);
    s.insert({MX * x + y, -1});
  }
  printf("%d", sol());
}