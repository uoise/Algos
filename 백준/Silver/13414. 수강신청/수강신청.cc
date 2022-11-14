#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
using isp = pair<int, string>;
unordered_map<string, int> wm;
vector<isp> rv;

int k, l;
void sol() {
  string lv[l];
  for (auto& i : lv) cin >> i;
  for (int i = 0; i < l; i++) {
    auto pos = wm.find(lv[i]);
    if (pos == wm.end())
      wm.insert({lv[i], i});
    else
      pos->second = i;
  }
  for (const auto& i : wm) rv.push_back({i.second, i.first});
  sort(rv.begin(), rv.end());
  for (int i = 0; i < k && i < rv.size(); i++) cout << rv[i].second << "\n";
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> k >> l;
  sol();
}
