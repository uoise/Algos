#include <cstdio>
#include <vector>

constexpr int MX = 2e6 + 1;

int T;
long long a, b;
bool bv[MX];
std::vector<long long> v;
void mpr() {
  bv[0] = bv[1] = 1;
  for (int i = 2; i < MX; i++) {
    if (bv[i]) continue;
    for (int j = 2; j * i < MX; j++) bv[j * i] = 1;
  }
  for (int i = 2; i < MX; i++)
    if (!bv[i]) v.push_back(i);
}

bool sol() {
  a += b;
  if (a == 2) return 0;
  if (!(a % 2)) return 1;
  a -= 2;
  if (a < MX) return !bv[a];
  for (const auto& i : v) {
    if (a < i) break;
    if (!(a % i)) return 0;
  }
  return 1;
}

int main() {
  scanf("%d", &T);
  mpr();
  while (T--) {
    scanf("%lld %lld", &a, &b);
    printf(sol() ? "YES\n" : "NO\n");
  }
}