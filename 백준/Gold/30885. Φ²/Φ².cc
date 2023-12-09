#include <cstdio>
#include <vector>

std::vector<std::pair<long long, int>> v, t;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    long long x;
    scanf("%lld", &x);
    v.push_back({x, i + 1});
  }

  while (v.size() > 1) {
    bool chk = false;
    for (int i = 0; i < v.size(); i++) {
      if (chk) {
        chk = false;
        continue;
      }

      auto k = v[i];
      long long c = 0;
      if (!t.empty() && t.back().first <= k.first) {
        c += t.back().first;
        t.pop_back();
      }

      if (i < v.size() - 1 && k.first >= v[i + 1].first)
        c += v[i + 1].first, chk = true;

      k.first += c;
      t.push_back(k);
    }
    v = t;
    t.clear();
  }

  printf("%lld %d", v[0].first, v[0].second);
}