#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
bool bv[100001];
int n, r;
string s;
unordered_map<string, int> um;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> s;
  while (--n) {
    cin >> s;
    if (s == "ENTER") {
      memset(bv, 0, sizeof bv);
      continue;
    }
    auto f = um.find(s);
    int idx;
    if (f == um.end())
      um.insert({s, idx = um.size()});
    else
      idx = f->second;
    if (!bv[idx]) bv[idx] = ++r;
  }
  cout << r;
}