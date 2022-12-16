#include <algorithm>
#include <cstdio>

using namespace std;
struct xyz {
  int x, y, z;
  bool operator<(const xyz& a) const {
    return z == a.z ? (x == a.x ? y < a.y : x < a.x) : z < a.z;
  }
};

constexpr int siz = 200'000;
int n, m, bv[siz];
xyz vv[siz];

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
  int res = 0, sum = 0, cnt = 0;
  for (int i = 0; i < m; i++) bv[i] = i;
  for (int i = 0; i < n; i++) {
    scanf("%d %d %d", &vv[i].x, &vv[i].y, &vv[i].z);
    res += vv[i].z;
  }
    
  if (n == m - 1) return 0;
  sort(vv, vv + n);
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