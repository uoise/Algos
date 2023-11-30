#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;
const string tgt = "ChongChong";
bool bv[100001];
int n, r;
string s, e;
unordered_map<string, int> um;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  um.insert({tgt, 0});
  bv[0] = 1;
  cin >> n;
  while (n--) {
    cin >> s >> e;
    auto f1 = um.find(s), f2 = um.find(e);
    int idx, jdx;
    if (f1 == um.end())
      um.insert({s, idx = um.size()});
    else
      idx = f1->second;
    if (f2 == um.end())
      um.insert({e, jdx = um.size()});
    else
      jdx = f2->second;
    if (bv[idx] || bv[jdx]) bv[idx] = bv[jdx] = 1;
  }
  for (int i = 0; i < um.size(); i++) r += bv[i];
  cout << r;
}