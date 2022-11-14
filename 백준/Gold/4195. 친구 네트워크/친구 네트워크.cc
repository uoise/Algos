#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
unordered_map<string, int> ns;
vector<pair<int, int>> vv;
int cnt;
int hsh(const string& s) {
  const auto res = ns.find(s);
  if (res == ns.end()) {
    ns.insert({s, ns.size()});
    return ns.size() - 1;
  }
  return res->second;
}

int fnd(int a) {
  if (a == vv[a].first) return a;
  return vv[a].first = fnd(vv[a].first);
}

void mks(int a, int b) {
  const int aa = fnd(a), bb = fnd(b);
  if (aa != bb) {
    if (aa > bb)
      vv[aa].first = bb;
    else
      vv[bb].first = aa;
    vv[bb].second = vv[aa].second = (vv[aa].second + vv[bb].second);
  }
  cout << vv[aa].second << '\n';
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int TC, f;
  string a, b;
  cin >> TC;
  while (TC--) {
    cin >> f;
    ns.clear();
    vv.assign(f * 2, {0, 1});
    for (int i = 0; i < vv.size(); i++) vv[i].first = i;
    for (int i = 0; i < f; i++) {
      cin >> a >> b;
      mks(hsh(a), hsh(b));
    }
  }
}