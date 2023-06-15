#include <algorithm>
#include <iostream>

using namespace std;

string s;
int n;
long long v[26], o, r;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    o = 1;
    for (int i = s.length() - 1; i >= 0; i--, o *= 10) v[s[i] - 'A'] -= o;
  }
  std::sort(v, v + 26);
  o = 0;
  for (int i = 9; i; i--, o++) r -= v[o] * i;
  cout << r;
}