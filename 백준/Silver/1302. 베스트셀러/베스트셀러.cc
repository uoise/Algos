#include <iostream>
#include <map>

using namespace std;

int n, x;
string s;
map<string, int> v;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout.tie(0);
  cin >> n;
  while (n--) {
    cin >> s;
    auto f = v.find(s);
    if (f == v.end())
      v.insert({s, 1});
    else
      f->second++;
  }

  for (auto& p : v)
    if (x < p.second) s = p.first, x = p.second;
  cout << s;
}