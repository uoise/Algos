#include <iostream>
#include <vector>

using namespace std;

vector<int> getPV(const string& s) {
  int sz = s.size(), j = 0;
  vector<int> pi(sz, 0);
  for (int i = 1; i < sz; i++) {
    while (j && (s[i] != s[j])) j = pi[j - 1];
    if (s[i] == s[j]) pi[i] = ++j;
  }
  return pi;
}

vector<int> kmp(const string& s, const string& p) {
  int pz = p.size(), j = 0;
  vector<int> res, pv = getPV(p);
  for (int i = 0; i < s.size(); i++) {
    while (j && (s[i] != p[j])) j = pv[j - 1];
    if (s[i] == p[j]) {
      if (j == pz - 1) {
        res.push_back(i - (pz - 1));
        j = pv[j];
      } else
        j++;
    }
  }
  return res;
}

int main() {
  string t, p;
  cout.tie(0);
  getline(cin, t);
  getline(cin, p);
  auto r = kmp(t, p);
  cout << r.size() << '\n';
  for (const auto& i : r) cout << i + 1 << '\n';
}