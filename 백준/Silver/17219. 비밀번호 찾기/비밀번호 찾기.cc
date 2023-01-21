#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<string, string> v;
int n, m;
string x, y;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout.tie(0);
  cin >> n >> m;
  while (n--) {
    cin >> x >> y;
    v.insert({x, y});
  }
  while (m--) {
    cin >> x;
    auto r = v.find(x);
    cout << r->second << '\n';
  }
}