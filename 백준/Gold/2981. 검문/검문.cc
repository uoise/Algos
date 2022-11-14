#include <algorithm>
#include <iostream>
#include <vector>
int gcd(int res, int inp) {
  while (inp != 0) {
    int t = res % inp;
    res = inp;
    inp = t;
  }
  return res;
}

void solve() {
  int N, i, g, t = 0;
  std::vector<int> v;
  std::vector<int> r;
  std::vector<int>::iterator it;
  scanf("%d", &N);
  for (i = 0; i < N; i++) {
    scanf("%d", &g);
    v.push_back(g);
  }
  std::sort(v.begin(), v.end());
  g = v[1] - v[0];
  for (i = 2; i < v.size(); i++) g = gcd(g, v[i] - v[i - 1]);
  for (i = 1; i * i <= g; i++)
    if (!(g % i)) {
      r.push_back(i);
      if (g / i != i) r.push_back(g / i);
    }
  std::sort(r.begin(), r.end());
  for (it = r.begin(); it != r.end(); it++)
    if (*it != 1) printf("%d ", *it);
}

int main() { solve(); }