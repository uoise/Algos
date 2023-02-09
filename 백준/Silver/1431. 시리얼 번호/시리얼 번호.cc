#include <algorithm>
#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

int n;
bool cmp(const string& x, const string& y) {
  if (x.length() != y.length()) return x.length() < y.length();
  int a = 0, b = 0;
  for (const auto& c : x)
    if (!isalpha(c)) a += (c - '0');
  for (const auto& c : y)
    if (!isalpha(c)) b += (c - '0');
  if (a != b) return a < b;
  return x < y;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout.tie(0);
  cin >> n;
  vector<string> v(n);
  for (auto& s : v) cin >> s;
  sort(v.begin(), v.end(), cmp);
  for (const auto& s : v) cout << s << '\n';
}