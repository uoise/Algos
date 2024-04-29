#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
unordered_set<string> i, o;
string s, e, q, p, t;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> s >> e >> q;
  while (cin >> t >> p) {
    if (t <= s) i.insert(p);
    else if (t >= e && t <= q && i.count(p)) o.insert(p);
  }
  cout << o.size();
}