#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool prio(pair<int, int> a, pair<int, int> b) {
  if ((a.first < b.first && a.second < b.second)) return true;
  return false;
}

void solve() {
  uint32_t T, i, x, y;
  cin >> T;
  vector<pair<uint32_t, uint32_t>> v;
  vector<pair<uint32_t, uint32_t>>::iterator it, jt;
  for (i = 0; i < T; i++) {
    cin >> x >> y;
    v.push_back(make_pair(x, y));
  }
  for (it = v.begin(); it != v.end(); it++) {
    i = 1;
    for (jt = v.begin(); jt != v.end(); jt++) {
      if (prio(*it, *jt)) i++;
    }
    cout << i << " ";
  }
  cout << '\n';
}

int main() { solve(); }