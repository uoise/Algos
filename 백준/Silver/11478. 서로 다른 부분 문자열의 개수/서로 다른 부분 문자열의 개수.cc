#include <iostream>
#include <set>
using namespace std;

void solve() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  set<string> ss;
  string s;
  cin >> s;
  int siz = s.size(), cur, i;
  cur = siz;
  while (cur--)
    for (i = 0; i <= siz - cur; i++) ss.insert(s.substr(i, cur));

  cout << ss.size() << '\n';
}

int main() { solve(); }
