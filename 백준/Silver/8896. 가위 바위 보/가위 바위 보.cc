#include <iostream>
#include <vector>

using namespace std;

int sol(const int n) {
  vector<string> kv(n);
  vector<bool> rv(n, 1);
  int r = n;
  for (auto& k : kv) cin >> k;
  int siz = kv[0].size();
  for (int i = 0; i < siz && r > 1; i++) {
    vector<int> rr, ss, pp;
    for (int j = 0; j < n; j++) {
      if (rv[j]) {
        if (kv[j][i] == 'R')
          rr.push_back(j);
        else if (kv[j][i] == 'S')
          ss.push_back(j);
        else
          pp.push_back(j);
      }
    }
    if (rr.size() && ss.size() && pp.size()) continue;
    if (pp.size() && ss.size())
      for (const auto& w : pp) {
        rv[w] = 0;
        --r;
      }
    else if (rr.size() && pp.size())
      for (const auto& w : rr) {
        rv[w] = 0;
        --r;
      }
    else if (ss.size() && rr.size())
      for (const auto& w : ss) {
        rv[w] = 0;
        --r;
      }
  }
  if (r == 1)
    for (int i = 0; i < n; i++)
      if (rv[i]) return i + 1;
  return 0;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int TC, n;
  cin >> TC;
  while (TC--) {
    cin >> n;
    cout << sol(n) << '\n';
  }
}