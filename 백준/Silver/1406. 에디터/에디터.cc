#include <iostream>
#include <list>
#include <string>

using namespace std;

list<char> r;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout.tie(0);
  string s;
  int m;
  char o;
  cin >> s >> m;
  for (const auto& c : s) r.push_back(c);
  auto it = r.end();
  while (m--) {
    cin >> o;
    switch (o) {
      case 'L':
        if (it != r.begin()) --it;
        break;
      case 'D':
        if (it != r.end()) ++it;
        break;
      case 'B':
        if (it != r.begin()) it = r.erase(--it);
        break;
      case 'P':
        cin >> o;
        r.insert(it, o);
        break;
    }
  }
  for (const auto& c : r) cout << c;
}