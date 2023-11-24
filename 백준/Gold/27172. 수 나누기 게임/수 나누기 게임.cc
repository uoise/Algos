#include <cstdio>
#include <unordered_set>

constexpr int MN = 1e5 + 1, MX = 1e6 + 1;

std::unordered_set<int> pr[MN];
bool bv[MX];
int n, v[MN], rv[MX];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    bv[v[i]] = 1;
    for (int j = 1; j * j <= v[i]; j++) {
      if (v[i] % j) continue;
      pr[i].insert(j);
      if (j * j != v[i]) pr[i].insert(v[i] / j);
    }
  }

  for (int i = 0; i < n; i++)
    for (const int& j : pr[i])
      if (bv[j]) ++rv[j], --rv[v[i]];

  for (int i = 0; i < n; i++) printf("%d ", rv[v[i]]);
}