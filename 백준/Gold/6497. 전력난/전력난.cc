#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;
struct xyz {
  int x, y, z;
  bool operator<(const xyz& a) const {
    return z == a.z ? (x == a.x ? y < a.y : x < a.x) : z < a.z;
  }
};

int n, m, bv[200'000];
int fnd(int x) {
  if (bv[x] == x) return x;
  return bv[x] = fnd(bv[x]);
}

int mks(int x, int y) {
  x = fnd(x), y = fnd(y);
  if (x == y) return 0;
  return bv[x] = y;
}

int sol() {
  vector<xyz> vv(n);
  int res = 0, sum = 0, cnt = 0;
  for (int i = 0; i < m; i++) bv[i] = i;
  for (auto& p : vv) {
    scanf("%d %d %d", &p.x, &p.y, &p.z);
    res += p.z;
  }

  if (n == m - 1) return 0;

  sort(vv.begin(), vv.end());
  for (const auto& p : vv) {
    if (mks(p.x, p.y)) {
      sum += p.z;
      if (++cnt == m - 1) break;
    }
  }

  return res - sum;
}

int main() {
  while (1) {
    scanf("%d %d", &m, &n);
    if (!n && !m) break;
    printf("%d\n", sol());
  }
}