#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

string s, t;
int sol() {
  cin >> s >> t;
  int r = 0, n = s.size();

  for (int i = 0; i < n; i++) {
    if (s[i] == '0' && t[i] == '1') {
      for (int j = 0; j < n; j++) {
        if (s[j] == '1' && t[j] == '0') {
          std::swap(s[i], s[j]);
          ++r;
          break;
        }
      }
    }
  }

  for (int i = 0; i < n; i++)
    if (s[i] == '0' && t[i] == '1') s[i] = '1', ++r;

  int qc = 0, zc = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '?' && t[i] == '1') ++qc;
    if (s[i] == '1' && t[i] == '0') ++zc;
  }

  if (qc < zc) return -1;

  for (int i = 0; i < n; i++) {
    if (s[i] == '1' && t[i] == '0') {
      for (int j = 0; j < n; j++) {
        if (s[j] == '?') {
          std::swap(s[i], s[j]);
          s[i] = '0', r += 2;
          break;
        }
      }
    }
  }

  for (int i = 0; i < n; i++)
    if (s[i] == '?') s[i] = t[i], ++r;

  return r;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int T;
  cin >> T;
  for (int i = 1; i <= T; i++) cout << "Case " << i << ": " << sol() << " \n";
}