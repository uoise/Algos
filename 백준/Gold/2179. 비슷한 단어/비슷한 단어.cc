#include <algorithm>
#include <iostream>

using namespace std;

struct is {
  int i;
  string s;
  bool operator<(const is &o) const { return s < o.s; }
};

constexpr int MN = 20001;
is v[MN];
string s[MN], t;
int n, l[MN], m = -1;
int len(const string &s1, const string &s2) {
  int l = 0;
  for (int i = 0; i < min(s1.size(), s2.size()); i++) {
    if (s1[i] != s2[i]) break;
    ++l;
  }
  return l;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    v[i] = {i, s[i]};
  }

  sort(v, v + n);
  for (int i = 1; i < n; i++) {
    int c = len(v[i - 1].s, v[i].s);
    m = max(m, c);
    l[v[i - 1].i] = max(l[v[i - 1].i], c), l[v[i].i] = max(l[v[i].i], c);
  }

  for (int i = 0; i < n; i++) {
    if (l[i] != m || (t.size() && t != s[i].substr(0, m))) continue;
    cout << s[i] << '\n';
    if (t.size()) break;
    t = s[i].substr(0, m);
  }
}