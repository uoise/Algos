#include <iostream>
#include <string>
using namespace std;

void solve() {
  uint32_t N, t = 0, i = 665;
  string tmp, res = "666";
  cin >> N;
  while (i++) {
    tmp = to_string(i);
    if (tmp.string::find(res) != string::npos) ++t;
    if (t == N) break;
  }
  cout << i << '\n';
}

int main() { solve(); }