#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

unordered_set<string> s;
string c = ".........";
bool vld() {
  if (c[4] != '.')
    if ((c[0] == c[4] && c[4] == c[8]) || (c[2] == c[4] && c[4] == c[6]))
      return 1;

  for (int i = 0; i < 3; i++) {
    if (c[i] != '.' && c[i] == c[i + 3] && c[i] == c[i + 6]) return 1;
    if (c[i * 3] != '.' && c[i * 3] == c[i * 3 + 1] && c[i * 3] == c[i * 3 + 2])
      return 1;
  }

  return 0;
}

void btr(const int n, const bool o) {
  if (n == 9 || vld()) {
    s.insert(c);
    return;
  }

  for (int i = 0; i < 9; i++) {
    if (c[i] != '.') continue;
    c[i] = o ? 'O' : 'X';
    btr(n + 1, !o);
    c[i] = '.';
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cout.tie(0);
  btr(0, 0);
  while (1) {
    cin >> c;
    if (c == "end") break;
    cout << (s.count(c) ? "valid\n" : "invalid\n");
  }
}