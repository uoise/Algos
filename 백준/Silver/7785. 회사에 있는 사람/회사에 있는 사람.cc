#include <iostream>
#include <set>

using namespace std;

set<string> st;
string n, o;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> o;
    if (o[0] == 'e') st.insert(n);
    else st.erase(n);
  }
  for (auto it = st.rbegin(); it != st.rend(); it++) cout << *it << '\n';
}