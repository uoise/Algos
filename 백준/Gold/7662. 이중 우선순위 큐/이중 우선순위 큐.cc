#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

void sol() {
  multiset<int> dq;
  char c;
  int k, n, siz = 0;
  cin >> k;
  while (k--) {
    cin >> c >> n;
    if (c == 'D') {
      if (dq.empty()) continue;
      if (n > 0) {
        dq.erase(--dq.end());
      } else {
        dq.erase(dq.begin());
      }
    } else {
      dq.insert(n);
    }
  }

  if (dq.empty())
    cout << "EMPTY\n";
  else {
    cout << *(--dq.end()) << ' ' << *dq.begin() << '\n';
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int tc;
  cin >> tc;
  while (tc--) sol();
}