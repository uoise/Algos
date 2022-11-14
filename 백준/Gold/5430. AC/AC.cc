#include <iostream>
using namespace std;
void inpp(const int& n, int* v, int& ri) {
  string s;
  cin >> s;
  if (n == 0) return;
  int tmp = 0;
  for (size_t i = 1; i < s.size(); i++) {
    if (s[i] == ',' || s[i] == ']') {
      v[ri++] = tmp;
      tmp = 0;
    } else {
      if (tmp != 0) tmp *= 10;
      tmp += (s[i] - '0');
    }
  }
}

void print(const bool& pos, const int& li, const int& ri, const int* v) {
  cout << '[';
  if (pos) {
    for (int i = li; i < ri; i++) {
      cout << v[i];
      if (ri - i != 1) cout << ',';
    }
  } else {
    for (int i = ri - 1; i >= li; i--) {
      cout << v[i];
      if (li != i) cout << ',';
    }
  }
  cout << "]\n";
}

bool solve() {
  int N, c = 1, li = 0, ri = 0;
  string S;
  bool pos = true;
  cin >> S >> N;
  int V[N];
  inpp(N, V, ri);
  for (size_t i = 0; i < S.size(); i++)
    if (S[i] == 'R') {
      pos = !pos;
    } else if (S[i] == 'D') {
      if (ri - li < 1) return false;
      (pos) ? li++ : ri--;
    }
  print(pos, li, ri, V);
  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T;
  cin >> T;
  while (T--)
    if (!solve()) cout << "error\n";
}