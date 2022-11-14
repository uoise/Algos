#include <algorithm>
#include <iostream>

using namespace std;

int r, vv[5];
void sol() {
  for (auto& i : vv) {
    cin >> i;
    r += i;
  }
  sort(vv, vv + 5);
  cout << r / 5 << "\n" << vv[2];
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  sol();
}