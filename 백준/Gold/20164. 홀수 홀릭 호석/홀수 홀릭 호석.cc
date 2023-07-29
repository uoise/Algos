#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

constexpr int INF = 1e9;
pair<int, int> sol(const string& s) {
  int r = 0;
  for (const auto& c : s) r += (c - '0') & 1 ? 1 : 0;
  if (s.length() == 1) return {r, r};

  pair<int, int> p;

  if (s.length() == 2) {
    auto p = sol(to_string(s[0] + s[1] - 2 * '0'));
    return {p.first + r, p.second + r};
  }

  int rm = INF, rx = 0;
  for (int i = 0; i < s.length() - 2; i++) {
    for (int j = i + 1; j < s.length() - 1; j++) {
      int t = stoi(s.substr(0, i + 1)) + stoi(s.substr(i + 1, j - i)) + stoi(s.substr(j + 1));
      p = sol(to_string(t));
      rm = min(rm, p.first), rx = max(rx, p.second);
    }
  }
  
  return make_pair(rm + r, rx + r);
}

int main() {
  string s;
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  const auto r = sol(s);
  cout << r.first << " " << r.second;
}