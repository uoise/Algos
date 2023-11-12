#include <cstdio>
#include <set>
#include <unordered_map>

std::unordered_map<int, std::set<int>> db;
int n, v[200001];
long long sv[200001];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &v[i]);
    sv[i] = v[i] + sv[i - 1];
    db[v[i]].insert(i);
  }

  long long mx = 0;
  int ct = 0;
  for (int r = 1; r <= n; r++) {
    int l = -1;
    for (const int& t : db[v[r]]) {
      if (t > r) continue;
      l = t;
      break;
    }
    if (l == -1) continue;
    long long t = sv[r] - sv[l - 1];
    if (t > mx) {
      mx = t, ct = 1;
    } else if (t == mx) {
      ++ct;
    }
  }
  printf("%lld %d", mx, ct);
}