#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

string s[16];
int n, r[6][1 << 16];
int cti(const char& c) {
  switch (c) {
    case 'A':
      return 1;
    case 'E':
      return 2;
    case 'I':
      return 3;
    case 'O':
      return 4;
    case 'U':
      return 5;
  }
  return 0;
}

int sol(char c, int b) {
  int& t = r[cti(c)][b];
  if (t != -1) return t;
  t = 0;
  for (int i = 0; i < n; i++) {
    if ((b & (1 << i)) || (c && (c != s[i][0]))) continue;
    t = max(t, sol(s[i][s[i].size() - 1], b | (1 << i)) + (int)s[i].size());
  }
  return t;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  memset(r, -1, sizeof r);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> s[i];
  cout << sol(0, 0);
}