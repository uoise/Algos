#include <algorithm>
#include <cstdio>
#include <unordered_map>
#include <vector>

std::vector<int> v;
std::unordered_map<int, int> m;
int n, d, k, c, r;
void aoi(int x) {
  auto f = m.find(x);
  if (f == m.end())
    m.insert({x, 1});
  else
    f->second++;
}

void eod(int x) {
  if (!--m[x]) m.erase(x);
}

int main() {
  scanf("%d %d %d %d", &n, &d, &k, &c);
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    v.push_back(x);
  }

  for (int i = 0; i < n + k; i++) {
    aoi(v[i % n]);
    if (i >= k) eod(v[(i - k) % n]);
    r = std::max(r, (int)(m.find(c) == m.end() ? m.size() + 1 : m.size()));
  }
  printf("%d", r);
}