#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

void solve() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int N, M, i, ts;
  string s;
  set<string> ss;
  vector<string> vv;
  vector<string>::iterator it;
  cin >> N >> M;
  while (N--) {
    cin >> s;
    ss.insert(s);
  }
  while (M--) {
    cin >> s;
    if (ss.count(s)) vv.push_back(s);
  }
  sort(vv.begin(), vv.end());
  cout << vv.size() << '\n';
  for (it = vv.begin(); it != vv.end(); it++) cout << *it << '\n';
}

int main() { solve(); }