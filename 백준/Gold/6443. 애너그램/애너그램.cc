#include <iostream>
#include <string>

using namespace std;

string s, r;
int n, b[26];
void btr() {
  if (s.size() == r.size()) {
    cout << r << '\n';
    return;
  }

  for (int i = 0; i < 26; i++) {
    if (!b[i]) continue;
    --b[i], r.push_back('a' + i);
    btr();
    ++b[i], r.pop_back();
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (const auto& c : s) ++b[c - 'a'];
    btr();
    for(int i = 0; i < 26; i++) b[i] = 0;
  }
}